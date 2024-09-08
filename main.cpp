#include <iostream>
#include <stdlib.h>
#include <string> 
#include <sstream>
#include <time.h>

#include "main.hpp"

using namespace std;

int singles[6] = {0, 0, 0, 0, 0, 0};
int bonus = 0;
int threeOfKind = 0, fourOfKind = 0, fullHouse = 0; 
int smallStraight = 0, largeStraight = 0;
int yahtzee = 0;
int chance = 0;

int bonusLeft = 63;

int rollCount = 3;
bool isScoreChanged[13];


int dice[5] = {1, 1, 1, 1, 1};
bool pauseDice[5] = {false, false, false, false, false};

int score1 = 0;

bool rolledDice;
bool isGameOver;
bool isWrongSelect = false;



int main() {
  srand(time(0));
  clear();

  for(int i = 0; i < 13; i++) {
    isScoreChanged[i] = false;
  }

  // Start text
  cout << "------------------\nWelcome to Yahtzee\n------------------" << endl;

  cout << "Please select menu" << endl;
  cout << "1. start new game\n2. end menu" << endl;

  int selection;
  cin >> selection;
    
  switch(selection) {
    case 1:
      clear();
      startGame();
      break;
    case 2:
      cout << "--------\nThank you!\n--------\n";
      break;
    default:
      cout << "Select a valid answer" << endl;
      break;
  }


  return 0;
}

void startMenu() {}

void startGame() {

  isGameOver = false;
  rolledDice = false;

  while(!isGameOver) {

    printUI(true);

    char select; 
    cin >> select;

    if((char)tolower(select) == 'p' && rolledDice) {
      plotScore(dice);
      rolledDice = false;
      cin.clear();
      fflush(stdin);
      resetDice(dice);
    }

    if((char)tolower(select) == 'r' && rollCount > 0) {
      rolledDice = true;
      rollDice(dice, pauseDice);
      rollCount--;
      cin.clear();
      fflush(stdin);
    }

    if((char)tolower(select) == 'l' && rollCount < 3) {
      lockDice(pauseDice);
      cin.clear();
      fflush(stdin);
    }
  }
}

string scoreSheet() {

  ostringstream str;
  str << "\nScore Sheet:\n----------\n1. Aces: " << singles[0] << "\n2. Twos: " << singles[1] << "\n3. Threes: " << singles[2] << "\n4. Fours: " << singles[3] << "\n5. Fives: " << singles[4] << "\n6. Sixes: " << singles[5] << "\n7. 3 of a kind: " << threeOfKind << "\n8. 4 of a kind: " << fourOfKind << "\n9. Full House: " << fullHouse << "\n10. Small Straight: " << smallStraight << "\n11. Large Straight: " << largeStraight << "\n12. Yahtzee: " << yahtzee << "\n13. Chance: " << chance << "\n\nBonus(" << bonusLeft << " left): " << bonus << "\n\nTotal Score: " << score1 << "\n----------\n" << endl;
  
  return str.str();
}

string diceDisplay() {

  ostringstream diceStr;
  diceStr << "dices: " << dice[0] << " " << dice[1] << " " << dice[2] << " " << dice[3] << " " << dice[4] << "\nlocks: ";
  for(int i = 0; i < 5; i++) {
    if(pauseDice[i]) {
      diceStr << "* ";
    } else {
      diceStr << "  ";
    }
  }
  diceStr << endl;
  return diceStr.str();
}
void printUI(bool printMenu) {
  clear();
  cout << "--------New Game--------" << endl;
  cout << scoreSheet() << endl;
  cout << diceDisplay() << endl;

  if(printMenu && rolledDice) {
    cout << "p. plot score" << endl;
  } else {
    cout << endl;
  }

  if(printMenu && rollCount > 0) {
    cout << "r. roll dice(roll count: " << rollCount << ")" << endl;
    if(rollCount < 3) {
      cout << "l. toggle dice" << endl;
    } else {
      cout << endl;
    }
  } else {
    cout << endl;
  }
    
  cout << "----------" << endl;
}

void rollDice(int dice[5], bool pauseDice[5]) {

  int lb = 1, ub = 6;
  for(int i = 0; i < 5; i++) {
    if(!pauseDice[i]) {
      dice[i] = rand() % ((ub - lb + 1)) + lb;
    }
  }
}

void lockDice(bool pauseDice[5]) {
  printUI(false);

  cout << "which dice?(1-5)" << endl;

  int num;
  cin >> num;
  while(num < 1 || num > 5) {
    cout << "wong selection, please try again" << endl;
    cin >> num;
  }
  pauseDice[num-1] = !pauseDice[num-1];
}

void resetDice(int dice[5]) {
  for(int i = 0; i < 5; i++) {
    dice[i] = 1;
    pauseDice[i] = false;
  }
  rollCount = 3;
}

void plotScore(int dice[5]) {
  // draw menu
  printUI(false);

  if(isWrongSelect) {
    cout << "you already used that slot!" << endl;
    isWrongSelect = false;
  }

  int type;

  cout << "Which one?" << endl;
  cin >> type;

  if(!isScoreChanged[type-1] && calcScore(type, dice) ) {
    isWrongSelect = false;

  } else {
    isWrongSelect = true;
    plotScore(dice);
  }
}

bool calcScore(int type, int dice[5]) {

  if(type < 7 && type > 0) {
    for(int i = 0; i < 5; i++) {
      if(dice[i] == type) {
        singles[type-1] += type;
      }
    }
    bonusLeft -= singles[type-1];
    if(bonusLeft <= 0) {
      bonusLeft = 0;
      bonus = 35;
      score1 += bonus;
    }
    isScoreChanged[type-1] = true;
    score1 += singles[type - 1];
    return true;
  }

  switch(type) {
    // 3 of kind
    case 7:
      if(nOfKind(dice, 3)) {
        threeOfKind = addAllDice(dice);
        isScoreChanged[6] = true;
        score1 += threeOfKind;
        return true; 
      } else {
        isScoreChanged[6] = true;
        return true;
      }
    case 8:
      if(nOfKind(dice, 4)) {
        fourOfKind = addAllDice(dice);
        isScoreChanged[7] = true;
        score1 += fourOfKind;
        return true;
      } else {
        isScoreChanged[7] = true;
        return true;
      }
    case 9:
      if(nOfKind(dice, 2) && nOfKind(dice, 3)) {
        fullHouse += 25;
        isScoreChanged[8] = true;
        score1 += fullHouse;
        return true;
      } else {
        isScoreChanged[8] = true;
        return true;
      }
    case 10:
      if(numInNRow(dice, 4)) {
        smallStraight += 30;
        isScoreChanged[9] = true;
        score1 += smallStraight;
        return true;
      } else {
        isScoreChanged[9] = true;
        return true;
      } 
    case 11:
     if(numInNRow(dice, 5)) {
       largeStraight += 40;
       isScoreChanged[10] = true;
       score1 += largeStraight;
       return true;
     } else {
       isScoreChanged[10] = true;
       return true;
     } 
    case 12:
     for(int i = 1; i < 5; i++) {
      if(dice[0] != dice[i]) {
        isScoreChanged[11] = true;
        return true;
        break;
      } 
     }
     yahtzee += 50;
     isScoreChanged[11] = true;
     score1 += yahtzee;
     return true;
    case 13:
     for(int i = 0; i < 5; i++) {
      chance += dice[i];
     }
     isScoreChanged[12] = true;
     score1 += chance;
     return true;
    default:
      return false;
  }

}


bool nOfKind(int dice[5], int n) {
  for(int i = 1; i <= 6; i++) {
    int counter = 0;
    for(int j = 0; j < 5; j++) {
     if(dice[j] == i) {
      counter++;
     }
     if(counter >= n) {
       return true;
      }
    }
  }
  return false;
}

bool numInNRow(int dice[5], int n) {
  
  // find smallest number
  int num = dice[0];
  for(int i = 1; i < 5; i++) {
    if(dice[i] < num) {
      num = dice[i];
    }
  }

  int nextNum = num;
  bool isCont = true;

  for(int i = 0; i < n; i++) {
    if(isCont) {
      isCont = false;
      nextNum++;
      for(int j = 0; j < 5; j++) {
        if(dice[j] == (nextNum)) {
          isCont = true; 
        }
      }
    } else {
      return false;
    }
  }
  
  return true;
}

int addAllDice(int dice[5]) {
  int res = 0;
  for(int i = 0; i < 5; i++) {
    res += dice[i];
  }
  return res;
}

void clear() {
#if defined _WIN32
    system("cls");
    //clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
    //std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
    system("clear");
#endif
}

