#include <stdio.h>
#include <stdlib.h>

void rotate(int** matrix, int matrixRowSize, int matrixColSizes) {
    for (int i = 0; i * 2 < matrixRowSize - 1; i++) {
        rotateCircle(matrix, i, matrixRowSize);
    }
}


void rotateCircle(int **matrix, int circleNum, int MatrixRowSize) {
    for (int i = 0; i < MatrixRowSize - circleNum * 2 - 1; i++) {
        int tmp = matrix[i + circleNum][circleNum];
        matrix[i + circleNum][circleNum] = matrix[MatrixRowSize - circleNum - 1][i + circleNum];
        matrix[MatrixRowSize - circleNum - 1][i + circleNum] = matrix[MatrixRowSize - i - circleNum - 1][MatrixRowSize - circleNum - 1];
        matrix[MatrixRowSize - i - circleNum - 1][MatrixRowSize - circleNum - 1] = matrix[circleNum][MatrixRowSize - i - circleNum - 1];
        matrix[circleNum][MatrixRowSize - i - circleNum - 1] = tmp;
    }
}


int main() {
    int **matrix = calloc(3, sizeof(int *));

    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    *matrix = a;
    *(matrix + 1) = b;
    *(matrix + 2) = c;
    rotate(matrix, 3, 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    free(matrix);
}
