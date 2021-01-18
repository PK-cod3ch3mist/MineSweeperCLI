![Image Header](https://github.com/PK-cod3ch3mist/MineSweeperCLI/blob/main/demo/Picture1.png)
# MineSweeper v1.1
A minesweeper game created in C++

New stuff (from *v1.0* to *v1.1*): 
- Fixed an issue/bug that would not allow the game to quit properly.
- Added box drawing characters for a better look and feel.
- Added other UNICODE characters for intuitive play.
- Fixed a bug that caused incorrect revealing of cells.

## Installation
Clone the repository.
```shell
git clone https://github.com/PK-cod3ch3mist/MineSweeperCLI.git
```
Then go to the directory of the game and run main.cpp with your favourite compiler/IDE. Alternatively, you can directly type the command for it on the terminal/console

## Requirements
All you need is a C++ compiler. If you are a macOS user, the executable inside the bin folder will work directly though.

ANSI escape sequence support will be good, otherwise you won't be able to see colours well. So if you are running this on windows, use Windows Subsystem for Linux (WSL).

This program now uses Unicode characters (Box Drawing, Flags and Geometric), please mention if this becomes an issue. (You could always try using the previous versions to fix this) 

## Gameplay
All instructions will be there in the game.
Starting Menu and Initial Play:

![Starting Menu and Initial Play](https://github.com/PK-cod3ch3mist/MineSweeperCLI/blob/main/demo/GIF1.gif)

The different difficulty levels differ in the number of mines (however the number of mines in a game is randomized to a degree)
Placing Flags: 

![Placing Flags](https://github.com/PK-cod3ch3mist/MineSweeperCLI/blob/main/demo/GIF2.gif)

Note that flags are denoted by a red Unicode character.
Losing/Revealing a Mine:

![Losing/Revealing Mine](https://github.com/PK-cod3ch3mist/MineSweeperCLI/blob/main/demo/GIF3.gif)
