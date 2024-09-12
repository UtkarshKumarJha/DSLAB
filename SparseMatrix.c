#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100


typedef struct {
    int row;
    int col;
    int value;
} Term;

void inputSparseMatrix(Term matrix[], int *numTerms, int *numRows, int *numCols) {
    int i;

    printf("Enter number of rows, columns, and non-zero terms: ");
    scanf("%d %d %d", numRows, numCols, numTerms);

    printf("Enter the non-zero terms (row, column, value):\n");
    for (i = 0; i < *numTerms; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}


void fastTranspose(Term matrix[], int numTerms, Term transposed[]) {
    int rowSize[MAX_TERMS + 1];
    int startingPos[MAX_TERMS + 1];
    int i;


    for (i = 0; i < MAX_TERMS + 1; i++) {
        rowSize[i] = 0;
        startingPos[i] = 0;
    }
    for (i = 0; i < numTerms; i++) {
        rowSize[matrix[i].col]++;
    }
    startingPos[0] = 0;
    for (i = 1; i <= MAX_TERMS; i++) {
        startingPos[i] = startingPos[i - 1] + rowSize[i - 1];
    }
    for (i = 0; i < numTerms; i++) {
        int row = matrix[i].col;
        int pos = startingPos[row]++;
        transposed[pos].row = matrix[i].col;
        transposed[pos].col = matrix[i].row;
        transposed[pos].value = matrix[i].value;
    }
}


void displaySparseMatrix(Term matrix[], int numTerms) {
    int i;

    for (i = 0; i < numTerms; i++) {
        printf("(%d, %d, %d) ", matrix[i].row, matrix[i].col, matrix[i].value);
    }
    printf("\n");
}

int main() {
    Term matrix[MAX_TERMS];
    Term transposed[MAX_TERMS];
    int numTerms, numRows, numCols;
    inputSparseMatrix(matrix, &numTerms, &numRows, &numCols);
    printf("Original Sparse Matrix:\n");
    displaySparseMatrix(matrix, numTerms);
    fastTranspose(matrix, numTerms, transposed);
    printf("Transposed Sparse Matrix:\n");
    displaySparseMatrix(transposed, numTerms);

    return 0;
}

