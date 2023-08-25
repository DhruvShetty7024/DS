#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
int playerX = 5;
int playerY = 10;
int obstacleX = 20;
int score = 0;
void clearScreen() {
    system("cls");
}

void draw() {
    clearScreen();

    for (int i = 0; i < playerY; i++) {
        printf("\n");
    }
    printf("O\n");

    for (int i = playerY + 1; i < 20; i++) {
        printf("\n");
    }

    for (int i = 0; i < obstacleX; i++) {
        printf(" ");
    }
    printf("X\n");

    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ') {
            playerY -= 2;
        }
    }
}

void update() {
    playerY++;
    obstacleX--;

    if (obstacleX <= 0) {
        obstacleX = 50;
        score++;
    }

    if (playerY >= 19) {
        playerY = 19;
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to Temple Run!\n");
    printf("Press spacebar to jump.\n");
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
