#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int **result = malloc(AColSizes[0]*sizeof(int*));
    *columnSizes = malloc(ARowSize*sizeof(int));
    for (int i = 0; i < AColSizes[0]; ++i) {
        (*columnSizes)[i] = ARowSize;
        result[i] = malloc(ARowSize*sizeof(int));
        for (int j = 0; j < ARowSize; ++j) {
            result[i][j] = A[j][i];
        }
    }
    *returnSize = AColSizes[0];
    return result;
}


int main() {
    // skipped
}
