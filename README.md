# Arcadium
This is a collection of three games written in C++. The games included in this suite are:

# 2048 Game

A puzzle game where the objective is to combine numbered tiles to reach a score of 2048.
The player can move tiles in four directions: up, down, left, and right.
If two tiles with the same number collide, they merge into a single tile with a value equal to their sum.
The game ends when the player reaches a score of 2048 or when there are no more valid moves.

# Sudoku Game
A logic-based number-placement puzzle game where the objective is to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 sub-grids contain all of the digits from 1 to 9.
The game starts with a partially filled grid. The player's task is to fill in the missing numbers (represented by 0) to solve the puzzle.
The player can enter a number from 1 to 9 in an empty cell. The cell can be selected by specifying the row and column number.
The game ends when the player has successfully filled in all the missing numbers.

# Word Search Game
A puzzle game where the player is presented with a rectangular board made up of cells, and the player's task is to search for a given word in the board.
The player inputs characters for each cell in the board. The player can search for a word by entering it into the program.
The program will search the board for the given word and display the result: if the word is found, the program will display the starting position of the word; if the word is not found, the program will display a message indicating that the word was not found.
The game ends when the player chooses to quit.

# How to Play
Detailed instructions for each game are included in the respective source code files.

# Installation
To run the games, you will need to compile the projdsa.cpp file using a C++ compiler. If you don't have a C++ compiler installed on your machine, you can download one such as MinGW (for Windows) or GCC (for Unix/Linux).

Once you have a C++ compiler installed, you can compile the projdsa.cpp file using the following command:
```
g++ projdsa.cpp -o Arcadium
```
This will create an executable file named Arcadium that you can run to start playing the games.

# Contributing
If you'd like to contribute to Arcadium, you can fork the project and make changes to the projdsa.cpp file. Once you've made your changes, you can submit a pull request to have your changes reviewed and merged into the main branch.
