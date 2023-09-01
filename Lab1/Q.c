//Q 220953504 skill issue
#include <stdio.h>
int main() {
    int n = 8;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 || i == n - 1) && (j > 0 && j < n - 1)) {
                printf("*");
            } else if (i > 0 && (j == 0 || j == n -1)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

