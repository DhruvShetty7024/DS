#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

void transpose(Element a[], Element b[], int numNonZero, int numRows, int numCols) {
    int rowTerms[numCols], startingPos[numCols];

    for (int i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
    }

    for (int i = 0; i < numNonZero; i++) {
        rowTerms[a[i].col]++;
    }

    startingPos[0] = 0;
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    for (int i = 0; i < numNonZero; i++) {
        int j = startingPos[a[i].col];
        b[j].row = a[i].col;
        b[j].col = a[i].row;
        b[j].value = a[i].value;
        startingPos[a[i].col]++;
    }
}

int main() {
    int numRows, numCols, numNonZero;
    printf("Enter number of rows, columns, and number of non-zero elements: ");
    scanf("%d %d %d", &numRows, &numCols, &numNonZero);

    Element original[numNonZero];
    printf("Enter non-zero elements (row col value):\n");
    for (int i = 0; i < numNonZero; i++) {
        scanf("%d %d %d", &original[i].row, &original[i].col, &original[i].value);
    }

    Element transposed[numNonZero];
    transpose(original, transposed, numNonZero, numRows, numCols);

    printf("Transposed sparse matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("%d\t%d\t%d\n", transposed[i].row, transposed[i].col, transposed[i].value);
    }

    return 0;
}
