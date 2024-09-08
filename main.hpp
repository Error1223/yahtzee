#include <iostream>
#include <string>

using namespace std;

void startMenu();

void startGame();

string scoreSheet();

string diceDisplay();

void printUI(bool printMenu);

void rollDice(int dice[5], bool pauseDice[5]);

void lockDice(bool pauseDice[5]);

void resetDice(int dice[5]);

void plotScore(int dice[5]);

bool calcScore(int type, int dice[5]);

int calcTotal();

bool nOfKind(int dice[5], int n);

bool numInNRow(int dice[5], int n);

int addAllDice(int dice[5]);

void clear();
