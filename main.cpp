//Created by Pratyush Kumar
//
//Copyright and License not decided yet

#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

#define SIZE 7

// Create a random grid creating function
// This function takes the difficulty, and array as argument
// It modifies a grid in return and returns it

void createGrid (int difLev, int playGrid[SIZE][SIZE]) {

    // Decide number of mines based on difficulty
    // For now, easy - 10 to 14 mines, medium - 15 to 18 mines, hard - 23 to 26 mines
    // To decide, can create an array or loop limit it
    int numMine = 0;
    switch (difLev) {
        case 1: numMine = 10 + rand()%5;
                break;
        case 2: numMine = 15 + rand()%5;
                break;
        case 3: numMine = 22 + rand()%5;
                break;
        default: cout << "Error: Difficulty level incorrectly specified, assuming medium...\n";
                 numMine = 15 + rand()%5;
                 break;
    }
    
    // Set the mines on the grid
    int posCol, posRow;
    posCol = posRow = 0;
    for (int i = 0; i < numMine; i++) {
        posRow = rand()%SIZE;
        posCol = rand()%SIZE;
        playGrid[posRow][posCol] = -1;
    }

    // Setting the Values
    // Use program mine162 for this
    int flag = 0;
    for (int i = 0; i < SIZE; i++) {
	    for (int j = 0; j < SIZE; j++) {
	        if(playGrid[i][j] == '.') {
		        if (playGrid[(i-1)][j] == '*') flag++;
		        if (playGrid[(i+1)][j] == '*') flag++;
		        if (playGrid[i][(j-1)] == '*') flag++;
		        if (playGrid[i][(j+1)] == '*') flag++;
		        if (playGrid[(i+1)][(j+1)] == '*') flag++;
		        if (playGrid[(i-1)][(j-1)] == '*') flag++;
		        if (playGrid[(i+1)][(j-1)] == '*') flag++;
		        if (playGrid[(i-1)][(j+1)] == '*') flag++;
	        }
	        flag = 0;
	    }
    }
}

// Create a reveal function

void reveal (char showGrid[SIZE][SIZE], int playGrid[SIZE][SIZE], int row, int col, bool select) {

    // If already discovered by another cell, then do not discover it again.
    // This is for speed and performance improvement
    // Implemented using the show grid instead of additional attribute
    if (showGrid[row][col] != '.' && showGrid[row][col] != 'P'){
        return;
    }

    // If Outside the bounds of the array, return
    if (row >= SIZE || row < 0 || col >= SIZE || col < 0){
        return;
    }

    // If it wasn't the selected cell of the player, proceed as follows
    if (select == false) {

        // If discovered cell is number, then return
        if (playGrid[row][col] != 0){
            if (playGrid[row][col] > 0)
                showGrid[row][col] = 48 + playGrid[row][col];
            return;
        }

        // If the discovered cell is empty, find other adjacent to it
        else {
            showGrid[row][col] = '_';
            reveal(showGrid, playGrid, row, col - 1, 0);
            reveal(showGrid, playGrid, row, col + 1, 0);
            reveal(showGrid, playGrid, row - 1, col, 0);
            reveal(showGrid, playGrid, row + 1, col, 0);
        }
    }

    // If it was the selected cell, proceed as follows
    else {

        // Display the cell
        if (playGrid[row][col] == 0) showGrid[row][col] = '_';
        else if (playGrid[row][col] > 0) showGrid[row][col] = 48 + playGrid[row][col];

        // If the selected cell was empty, i.e zero cell, proceed as follows
        if (playGrid[row][col] == 0) {
            reveal(showGrid, playGrid, row, col - 1, 0);
            reveal(showGrid, playGrid, row, col + 1, 0);
            reveal(showGrid, playGrid, row - 1, col, 0);
            reveal(showGrid, playGrid, row + 1, col, 0);
        }
    }

    // In all other cases, including errors and selected cell a number cell, return
    return;
}

void display (char showGrid[SIZE][SIZE]) {
    cout << "\\ | 0 1 2 3 4 5 6\n";
    cout << "------------------\n";
    for (int i = 0; i < SIZE; i++){
        cout << i << " |";
        for (int j = 0; j < SIZE; j++){
            cout << " " << showGrid[i][j];
        }
        cout << endl;
    }
}

int main () {
    char showGrid[SIZE][SIZE];
    int playGrid[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            showGrid[i][j] = '.';
            playGrid[i][j] = 0;
        }
    }

    system("clear");

    cout << "###### Welcome To Minesweeper v1.0 ######\n";
    cout << "-----------------------------------------\n";
    cout << "Select a difficulty level:\n";
    cout << "Select 1 for Easy\nSelect 2 for Medium\nSelect 3 for Hard\n";
    cout << "Your choice: ";
    int diffLev = 0;
    cin >> diffLev;

    createGrid(diffLev, playGrid);

    system("clear");

    // Saving space for time measurements
    
    int check = 0;
    int ch = 2;
    int row = 0;
    int col = 0;
    char cont = 'y';
    
    while (cont == 'y') {
        system("clear");
        display(showGrid);
        cout << "Enter 1 to place flag and 2 to reveal cell\nEnter Value: ";
        cin >> ch;
        cout << "Enter indices for location (row then column): ";
        cin >> row >> col;
        switch (ch){
            case 1: showGrid[row][col] = 'P';
                    break;
            case 2: if (playGrid[row][col] == -1){
                        // The Game Over sequence
                        for (int i = 0; i < SIZE; i++) {
                            for(int j = 0; j < SIZE; j++) {
                                if (playGrid[i][j] == -1) {
                                    showGrid[i][j] = '*';
                                }
                            }
                        }
                        display(showGrid);
                        cout << "You lose !!";
                        return 0;
                    }
                    reveal(showGrid, playGrid, row, col, true);
                    break;
        }

        // Check for complete filling
        check = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++){
                if (showGrid[i][j] == '.') {
                    check = 0;
                    break;
                }
            }
        }
        if (check != 0) {
            for (int i = 0; i < SIZE; i++) {
                for(int j = 0; j < SIZE; j++) {
                    if (playGrid[i][j] != -1 && showGrid[i][j] == 'P') {
                        check = 0;
                    }
                }
            }
            if (check != 0) {
                cout << "YOU WIN !!";
                return 0;
            }
        }
        cout << "Continue to next move? (ny): ";
        cin >> cont;
    }
    return 0;
}
