#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** imageSmoother(int** M, int MRowSize, int MColSize, int** columnSizes, int* returnSize) {
    int tmpScore;
    int gridNum;
    int **result = malloc(MRowSize * sizeof(int*));
    *returnSize = MRowSize;
    *columnSizes = malloc(MRowSize * sizeof(int));
    for (int i = 0; i < MRowSize; i++) {
        (*columnSizes)[i] = MColSize;
    }
    for (int i = 0; i < MRowSize; i++) {
        result[i] = malloc(MColSize * sizeof(int));
        for (int j = 0; j < MColSize; j++) {
            gridNum = 0;
            tmpScore = calc(M, i, j, MRowSize, MColSize, &gridNum);
            result[i][j] = tmpScore / gridNum;
        }
    }
    return result;
}


int calc(int** M, int i, int j, int r, int c, int* num) {
    int result = 0;
    for (int x = i - 1; x <= i + 1; x++) {
        for (int y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < r && y >= 0 && y < c) {
                (*num)++;
                result += M[x][y];
            }
        }
    }
    return result;
}

int main() {
    int **M = malloc(3 * sizeof(int*));
    int a[] = {1, 4, 5};
    int b[] = {6, 7, 8};
    int c[] = {1, 2, 3};
    M[0] = a;
    M[1] = b;
    M[2] = c;
    int *columnSizes;
    int returnSize;
    int **result = imageSmoother(M, 3, 3, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        free(result[i]);
        printf("\n");
    }
    free(result);
    free(columnSizes);
}
