# Sudoku-Helper | Developed for Advanced C++/OOPP

Input a File with an unsolved Sudoku Puzzle. A board will be displayed and a menu will appear. 

Choose an Option:

(1) Mark a Square with a number  
(2) Undo move  
(3) Redo move  
(4) Save current puzzle to a file  
(5) Restore puzzle from a file  
(6) Quit  

The Program is designed to display all options for each square after marking one. It is designed to help you solve the Sudoku Puzzle.

Development: Object Oriented Programming (OOP)

State (of a Square) -> Square -> Board (of many Squares) -> Clusters (of Squares on the Board)


https://replit.com/@AdvancedC/P12-Sudoku-Helper-Final-Version?v=1

To Test: Sign in -> Fork -> Run

# Instructions for makefile:

make P12

# Edit Makefile to change file input from command line
Default file: puzt.txt

Options:
puzt.txt
puzs.txt
puzd.txt

# Normal Compilation
g++ -o P12 *.cpp && ./P12 puzt.txt

# Valgrind Command
valgrind --leak-check=yes ./P12 puzt.txt

![img1](https://github.com/KazemoKaos/Sudoku-Helper/assets/34223008/09151503-3a13-484a-9657-3698d091721c)
![img2](https://github.com/KazemoKaos/Sudoku-Helper/assets/34223008/3552a1b5-ce28-4b00-a222-7a19d0427ae2)
![img3](https://github.com/KazemoKaos/Sudoku-Helper/assets/34223008/881023b9-1b35-4fc1-aa54-d61a04c1211a)
