#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generateCombine(int n, int k, int pos, int index, int *initial, int *tmpResult, int **result, int *count) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            *(*(result + *count) + i) = tmpResult[i];
        }
        (*count)++;
        return;
    }
    for (int i = pos; i < n; i++) {
        tmpResult[index] = initial[i];
        generateCombine(n, k, i + 1, index + 1, initial, tmpResult, result, count);
    }
}


int nChoosek(int n, int k) {
    int result = 1;
    // just to prevent overflow when calculating nCk.
    int a = k < n / 2 ? k : n - k;
    for (int i = n; i > n - a; i--) {
        result *= i;
    }
    for (int i = 1; i <= a; i++) {
        result /= i;
    }
    return result;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = (int)pow(2, numsSize);
    *columnSizes = calloc(*returnSize, sizeof(int));
    int start = 0;
    for (int i = 0; i <= numsSize; i++) {
        int tmpSize = nChoosek(numsSize, i);
        for (int j = 0; j < tmpSize; j++) {
            *(*columnSizes + start + j) = i;
        }
        start += tmpSize;
    }
    int **result = calloc(*returnSize, sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = calloc(*(*columnSizes + i), sizeof(int));
    }
    int count = 1;
    for (int i = 1; i <= numsSize; i++) {
        int tmpResult[i];
        generateCombine(numsSize, i, 0, 0, nums, tmpResult, result, &count);
    }
    return result;
}


// using bit manipulation
int** subsetsSmart(int* nums, int numsSize, int** columnSizes, int* returnSize) {
    *returnSize = 1 << numsSize;
    int **result = malloc(10000*sizeof(int*));
    *columnSizes = malloc(10000*sizeof(int));
    for (int i = 0; i < 1 << numsSize; ++i) {
        int tmp[100] = {0};
        int k = 0;
        for (int j = 0; j < numsSize; ++j) {
            if (i & (1 << j)) {
                tmp[k++] = nums[j];
            }
        }
        (*columnSizes)[i] = k;
        result[i] = malloc(k*sizeof(int));
        memcpy(result[i], tmp, k*sizeof(int));
    }
    return result;
}


int main() {
    int nums[3] = {1,2,3};
    int *columnSizes;
    int returnSize;
    int **result = subsets(nums, 3, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("{ ");
        for (int j = 0; j < * (columnSizes + i); j++) {
            printf("%d ", *(*(result + i) + j));
        };
        printf("}");
    }
    for (int i = 0; i < returnSize; i++) {
        free(*(result + i));
    }
    free(result);
    free(columnSizes);
}
