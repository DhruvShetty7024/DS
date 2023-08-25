#include <stdio.h>
#include <conio.h>
#include <windows.h>

int dinoY = 10;
int gravity = 1;
int isJumping = 0;
int gameover = 0;

void clearScreen() {
    system("cls");
}

void draw() {
    clearScreen();

    for (int i = 0; i < dinoY; i++) {
        printf("\n");
    }
    printf("D\n");

    for (int i = dinoY + 1; i < 20; i++) {
        printf("\n");
    }
}

void input() {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' && dinoY == 10) {
            isJumping = 1;
        }
    }
}

void update() {
    if (isJumping) {
        dinoY--;
        gravity = 0;
        if (dinoY <= 5) {
            isJumping = 0;
            gravity = 1;
        }
    } else if (dinoY < 10) {
        dinoY += gravity;
        gravity++;
    }
}

int main() {
    printf("Welcome to Dino Rush!\n");
    printf("Press spacebar to jump.\n");
    printf("Press any key to start...");
    _getch();

    while (!gameover) {
        draw();
        input();
        update();
        Sleep(100); // Sleep to control game speed
    }

    return 0;
}
