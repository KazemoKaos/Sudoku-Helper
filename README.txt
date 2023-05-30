Developed for Advanced C++/OOPP Course @ UNH

![Alt text](https://github.com/KazemoKaos/Sudoku-Helper/blob/main/sudoku1.png)
![Alt text](https://cdn.discordapp.com/attachments/1010766384646602856/1113178759416262666/image.png)

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
