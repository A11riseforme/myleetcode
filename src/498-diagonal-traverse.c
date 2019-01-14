#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** matrix, int matrixRowSize, int matrixColSize, int* returnSize) {
    *returnSize = matrixRowSize * matrixColSize;
    int *result = malloc(matrixRowSize * matrixColSize * sizeof(int));
    // deal with special case of one row.
    if (matrixRowSize == 1) {
        for (int i = 0; i < matrixColSize; ++i) {
            result[i] = matrix[0][i];
        }
        return result;
    }
    // deal with special case of one column.
    if (matrixColSize == 1) {
        for (int i = 0; i < matrixRowSize; ++i) {
            result[i] = matrix[i][0];
        }
        return result;
    }
    int pos[2] = {0, 1};
    result[0] = matrix[0][0];
    char dir = 'r';
    for (int i = 1; i < matrixRowSize * matrixColSize; ++i) {
        result[i] = mRead(matrix, matrixRowSize, matrixColSize, pos, &dir);
    }
    return result;
}


int mRead(int** matrix, int r, int c, int* pos, char* dir) {
    //printf("now at (%d, %d), prev dir is %c\n", pos[0], pos[1], *dir);
    if (*dir == 'r') {
        if (pos[0] == 0) {
            *dir = 'x';
            ++pos[0];
            --pos[1];
            return matrix[pos[0] - 1][pos[1] + 1];
        }
        *dir = 'y';
        --pos[0];
        ++pos[1];
        return matrix[pos[0] + 1][pos[1] - 1];
    }
    if (*dir == 'd') {
        if (pos[1] == 0) {
            *dir = 'y';
            --pos[0];
            ++pos[1];
            return matrix[pos[0] + 1][pos[1] - 1];
        }
        *dir = 'x';
        ++pos[0];
        --pos[1];
        return matrix[pos[0] - 1][pos[1] + 1];
    }
    if (*dir == 'y') {
        if (pos[0] == 0 && pos[1] != c - 1) {
            *dir = 'r';
            ++pos[1];
            return matrix[pos[0]][pos[1] - 1];
        }
        if (pos[1] == c - 1) {
            *dir = 'd';
            ++pos[0];
            return matrix[pos[0] - 1][pos[1]];
        }
        --pos[0];
        ++pos[1];
        return matrix[pos[0] + 1][pos[1] - 1];
    }
    if (pos[1] == 0 && pos[0] != r - 1) {
        *dir = 'd';
        ++pos[0];
        return matrix[pos[0] - 1][pos[1]];
    }
    if (pos[0] == r - 1) {
        *dir = 'r';
        ++pos[1];
        return matrix[pos[0]][pos[1] - 1];
    }
    ++pos[0];
    --pos[1];
    return matrix[pos[0] - 1][pos[1] + 1];
}


int main() {
    int **matrix = malloc(3 * sizeof(int*));
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    int returnSize;
    int *result = findDiagonalOrder(matrix, 3, 3, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    free(matrix);
    return 0;
}
