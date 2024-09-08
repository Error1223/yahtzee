# yahtzee
Command line game of a single player Yahtzee

##How to install
1. clone the files into your system
`git clone "https://github.com/Error1223/yahtzee.git"`
2. navigate into the build file
`cd build`
4. compile to control version(make sure cmake and make is installed)
`make`
5. run the game with the generated run command
`./yahtzee`

##How to play
This game was inspired by [buddy boardgames yahtzee](https://buddyboardgames.com/yahtzee)

A typical turn
First, you roll your dice, with the Roll command. Based on what you rolled, you can score one row on your scoresheet, based on the following rules:
- Ones:	Sum all the ones that you've rolled
- Twos:	Sum all the twos that you've rolled
- Threes:	Sum all the threes that you've rolled
- Fours:	Sum all the fours that you've rolled
- Fives:	Sum all the fives that you've rolled
- Sixes:	Sum all the sixes that you've rolled
- Three of a kind:	If you have three of a kind, sum all your dice
- Four of a kind:	If you have four of a kind, sum all your dice
- Full house:	Three of a kind and two of a different kind (ex: 3,3,3,2,)
- Small straight:	Four in a row (ex: 1,2,3,4)
- Large straight:	Five in a row (ex: 2,3,4,5,6)
- Yahtzee:	Five of a kind - at least 50. See below for more details
- Chance:	Sum all your dice

If you don’t like what you've rolled, don't worry - you have a total of three rolls every turn. Before your next roll, you may choose to keep dice by clicking or tapping on them. This will prevent those dice from being rolled. For example, if you've rolled 6,6,6,1,2 on your first roll, you may want to keep your sixes and roll for a four of a kind or Yahtzee.

The game continues until all players have filled out all rows, at which point the person with the most points wins.

You now know how to play Yahtzee! But there's a few more special rules you may want to learn:

###The bonus
The top section is the first six rows - ones, twos, threes, fours, fives and sixes. If the sum of your score in the top section is greater than or equal to 63, you automatically get 35 bonus points. Spectacular!
