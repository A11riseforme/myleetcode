#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** A, int ARowSize, int *AColSizes, int** columnSizes, int* returnSize) {
    int **result = malloc(ARowSize * sizeof(int*));
    *columnSizes = malloc(ARowSize * sizeof(int));
    for (int i = 0; i < ARowSize; ++i) {
        result[i] = malloc(AColSizes[i] * sizeof(int));
        (*columnSizes)[i] = AColSizes[i];
    }
    for (int i = 0; i < ARowSize; ++i) {
        for (int j = 0; j < AColSizes[i]; ++j) {
            result[i][j] = 1 - A[i][AColSizes[i] - j - 1];
        }
    }
    *returnSize = ARowSize;
    return result;
}


int main(int argc, char** argv) {
    int **nums = malloc(4 * sizeof(int*));
    int a[] = {1, 1, 0, 0};
    int b[] = {1, 0, 0, 1};
    int c[] = {0, 1, 1, 1};
    int d[] = {1, 0, 1, 0};
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;
    nums[3] = d;
    int returnSize;
    int *columnSizes;
    int numsColSizes[] = {4, 4, 4, 4};
    int **result = flipAndInvertImage(nums, 4, numsColSizes, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[j]; ++j) {
            printf("%d ", result[i][j]);
        }
        free(result[i]);
        printf("\n");
    }
    free(result);
    free(columnSizes);
    return 0;
}
