#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** nums, int numsRowSize, int numsColSize, int r, int c, int** columnSizes, int* returnSize) {
    if (numsRowSize*numsColSize != r*c) {
        *returnSize = numsRowSize;
        *columnSizes = malloc(numsRowSize*sizeof(int));
        for (int i = 0; i < numsRowSize; i++) {
            (*columnSizes)[i] = numsColSize;
        }
        return nums;
    }
    *returnSize = r;
    *columnSizes = malloc(r*sizeof(int));
    int **result = malloc(r*sizeof(int*));
    int k = 0;
    for (int i = 0; i < r; i++) {
        result[i] = malloc(c*sizeof(int));
        (*columnSizes)[i] = c;
        for (int j = 0; j < c; j++) {
            result[i][j] = nums[k/numsColSize][k%numsColSize];
            k++;
        }
    }
    return result;
}


int main() {
    int **nums = malloc(2*sizeof(int*));
    int a[] = {1,2};
    int b[] = {3,4};
    nums[0] = a;
    nums[1] = b;
    int *columnSizes;
    int returnSize;
    int **result = matrixReshape(nums, 2, 2, 1, 4, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}
