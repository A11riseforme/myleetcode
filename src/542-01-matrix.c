#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */;
int** updateMatrix(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize) {
    int **result = malloc(matrixRowSize * sizeof(int*));
    for (int i = 0; i < matrixRowSize; ++i) {
        result[i] = malloc(matrixColSize * sizeof(int));
        for (int j = 0; j < matrixColSize; ++j) {
            result[i][j] = INT_MAX;
        }
    }
    *returnSize = matrixRowSize;
    *columnSizes = malloc(matrixRowSize * sizeof(int));
    for (int i = 0; i < matrixRowSize; ++i) {
        (*columnSizes)[i] = matrixColSize;
    }
    for (int i = 0; i < matrixRowSize; ++i) {
        for (int j = 0; j < matrixColSize; ++j) {
            if (matrix[i][j] == 0) {
                result[i][j] = 0;
            } else {
                if (i > 0) {
                    result[i][j] = MIN(result[i][j], result[i - 1][j] + 1);
                }
                if (j > 0) {
                    result[i][j] = MIN(result[i][j], result[i][j - 1] + 1);
                }
            }
        }
    }
    for (int i = matrixRowSize - 1; i >= 0; --i) {
        for (int j = matrixColSize - 1; j >= 0; --j) {
            if (matrix[i][j]) {
                if (i < matrixRowSize - 1) {
                    result[i][j] = MIN(result[i][j], result[i + 1][j] + 1);
                }
                if (j < matrixColSize - 1) {
                    result[i][j] = MIN(result[i][j], result[i][j + 1] + 1);
                }
            }
        }
    }
    return result;
}


int main() {
    int **matrix = malloc(3 * sizeof(int*));
    int a[] = {0, 0, 0};
    int b[] = {0, 1, 0};
    int c[] = {1, 1, 1};
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    int *columnSizes;
    int returnSize;
    int **result = updateMatrix(matrix, 3, 3, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(result);
    free(columnSizes);
    return 0;
}
