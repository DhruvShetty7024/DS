#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int playerX = 5;
int roadWidth = 10;

void clearScreen() {
    system("cls");
}

void draw() {
    clearScreen();

    for (int i = 0; i < roadWidth; i++) {
        if (i == playerX) {
            printf("A");
        } else {
            printf("-");
        }
    }
    printf("\n");
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == 'a' && playerX > 0) {
            playerX--;
        } else if (key == 'd' && playerX < roadWidth - 1) {
            playerX++;
        }
    }
}

void update() {
    // Implement game logic (e.g., obstacles, scoring) here
}

int main() {
    printf("Welcome to Racing Game!\n");
    printf("Use 'A' and 'D' to move left and right.\n");
    printf("Press any key to start...");
    _getch();

    while (1) {
        draw();
        input();
        update();
        Sleep(100); // Sleep to control game speed
    }

    return 0;
}
