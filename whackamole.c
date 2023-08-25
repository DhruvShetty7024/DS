#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 5
#define MOLES 15

int board[BOARD_HEIGHT][BOARD_WIDTH];
int score = 0;

void clearScreen() {
    system("cls");
}

void initializeBoard() {
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            board[i][j] = 0;
        }
    }
}

void displayBoard() {
    clearScreen();
    for (int i = 0; i < BOARD_HEIGHT; i++) {
        for (int j = 0; j < BOARD_WIDTH; j++) {
            if (board[i][j] == 0) {
                printf("O ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void placeMoles() {
    for (int i = 0; i < MOLES; i++) {
        int row = rand() % BOARD_HEIGHT;
        int col = rand() % BOARD_WIDTH;
        board[row][col] = 1;
    }
}

int main() {
    srand(time(NULL));
    initializeBoard();

    printf("Welcome to Whack-a-Mole!\n");
    printf("Instructions: Press 'W' to move up, 'S' to move down, and 'E' to whack a mole.\n");
    printf("Press any key to start...");
    _getch();

    while (1) {
        displayBoard();
        int input = _getch();
        if (input == 'w') {
            if (score > 0) {
                score--;
            }
        } else if (input == 's') {
            if (score < MOLES) {
                score++;
            }
        } else if (input == 'e') {
            if (board[BOARD_HEIGHT - 1][score] == 1) {
                board[BOARD_HEIGHT - 1][score] = 0;
                score++;
            }
        }
        placeMoles();
        Sleep(500); // Pause for a while to give player time to react
    }

    return 0;
}
