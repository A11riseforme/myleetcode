#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// standard dfs method
void dfs(int* candidates, int candidatesSize, int target, int** result, int** columnSizes, int* tmp, int size, int pos, int *totalSize) {
    if (target < 0) {
        return;
    }
    if (target == 0) {
        result[*totalSize] = malloc(size * sizeof(int));
        (*columnSizes)[*totalSize] = size;
        for (int i = 0; i < size; ++i) {
            result[*totalSize][i] = tmp[i];
        }
        ++(*totalSize);
        return;
    }
    for (int i = pos; i < candidatesSize; ++i) {
        if (i == pos || candidates[i] != candidates[i - 1]) {
            tmp[size] = candidates[i];
            dfs(candidates, candidatesSize, target - candidates[i], result, columnSizes, tmp, size + 1, i + 1, totalSize);
        }
    }
    return;
}


int cmp(const void * a, const void * b) {
    return (*(int*)a - * (int*)b);
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum2(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    qsort(candidates, candidatesSize, sizeof(int), cmp);
    int *tmp = malloc(100 * sizeof(int));
    int **result = malloc(10000 * sizeof(int*));
    (*columnSizes) = malloc(10000 * sizeof(int));
    *returnSize = 0;
    dfs(candidates, candidatesSize, target, result, columnSizes, tmp, 0, 0, returnSize);
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */

    int nums[] = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    int *columnSizes;
    int returnSize;
    int **result = combinationSum2(nums, sizeof(nums) / sizeof(nums[0]), target, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(columnSizes);
    free(result);
    return 0;
}
