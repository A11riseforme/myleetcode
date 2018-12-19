#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    int *row = calloc(matrixRowSize, sizeof(int));
    int *col = calloc(matrixColSize, sizeof(int));
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < matrixRowSize; i++) {
        if (row[i] == 1) {
            for (int j = 0; j < matrixColSize; j++) {
                matrix[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < matrixColSize; i++) {
        if (col[i] == 1) {
            for (int j = 0; j < matrixRowSize; j++) {
                matrix[j][i] = 0;
            }
        }
    }
    free(row);
    free(col);
}


int main() {
    int **matrix = calloc(5, sizeof(int *));
    int a[] = {0,0,0,5};
    int b[] = {4,3,1,4};
    int c[] = {0,1,1,4};
    int d[] = {1,2,1,3};
    int e[] = {0,0,1,1};
    *(matrix + 0 ) = a;
    *(matrix + 1 ) = b;
    *(matrix + 2 ) = c;
    *(matrix + 3 ) = d;
    *(matrix + 4 ) = e;
    setZeroes(matrix, 5, 4);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++) {
        free(*(matrix + i));
    }
    free(matrix);
}
