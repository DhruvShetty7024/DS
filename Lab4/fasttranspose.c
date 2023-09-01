#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void fastTranspose(Element a[], Element b[], int m, int n) {
    int rowTerms[n], startingPos[n];

    for (int i = 0; i < n; i++) {
        rowTerms[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        rowTerms[a[i].col]++;
    }

    startingPos[0] = 0;
    for (int i = 1; i < n; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 0; i < m; i++) {
        int j = startingPos[a[i].col];
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
        startingPos[a[i].col]++;
    }
}

int main() {
    int m, n, numNonZero;
    printf("Enter number of rows, columns, and number of non-zero elements: ");
    scanf("%d %d %d", &m, &n, &numNonZero);

    Element a[numNonZero];
    printf("Enter non-zero elements (row col value):\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &a[i].row, &a[i].col, &a[i].value);
    }

    Element b[numNonZero];
    fastTranspose(a, b, numNonZero, n);

    printf("Fast Transpose of the sparse matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("%d\t%d\t%d\n", b[i].row, b[i].col, b[i].value);
    }

    return 0;
}
