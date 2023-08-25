#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int i, j, height = 20, width = 20;
int gameover, x, y, fruitx, fruity, score;
int tailX[100], tailY[100];
int nTail;
int flag;

void setup() {
    gameover = 0;

    // Initialize snake position
    x = height / 2;
    y = width / 2;

    // Initialize fruit position
    fruitx = rand() % height;
    fruity = rand() % width;

    score = 0;
}

void draw() {
    system("cls");

    // Draw the upper wall
    for (i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (j == 0)
                printf("#"); // Draw left wall
            if (i == y && j == x)
                printf("O"); // Draw snake head
            else if (i == fruity && j == fruitx)
                printf("F"); // Draw fruit
            else {
                int print = 0;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printf("o"); // Draw snake body
                        print = 1;
                    }
                }
                if (print == 0)
                    printf(" ");
            }

            if (j == width - 1)
                printf("#"); // Draw right wall
        }
        printf("\n");
    }

    // Draw the lower wall
    for (i = 0; i < width + 2; i++)
        printf("#");
    printf("\n");

    printf("Score: %d\n", score);
}

void input() {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a':
                flag = 1;
                break;
            case 's':
                flag = 2;
                break;
            case 'd':
                flag = 3;
                break;
            case 'w':
                flag = 4;
                break;
            case 'x':
                gameover = 1;
                break;
        }
    }
}

void logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (flag) {
        case 1:
            x--;
            break;
        case 2:
            y++;
            break;
        case 3:
            x++;
            break;
        case 4:
            y--;
            break;
        default:
            break;
    }

    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameover = 1;
    }

    if (x == fruitx && y == fruity) {
        score += 10;
        fruitx = rand() % width;
        fruity = rand() % height;
        nTail++;
    }
}

int main() {
    char c;
    setup();
    while (!gameover) {
        draw();
        input();
        logic();
        Sleep(10); // Sleep for a while to control the speed of the game
    }
    return 0;
}
