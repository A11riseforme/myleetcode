#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */

typedef struct {
    int size;
    int *sum;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *result = malloc(1 * sizeof(NumArray));
    result[0].size = numsSize;
    result[0].sum = malloc((numsSize + 1) * sizeof(int));
    result[0].sum[0] = 0;
    for (int i = 0; i < numsSize; ++i) {
        result[0].sum[i + 1] = nums[i] + result[0].sum[i];
    }
    return result;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    if (!obj) {
        return 0;
    }
    return obj->sum[j + 1] - obj->sum[i];
}

void numArrayFree(NumArray* obj) {
    free(obj->sum);
    free(obj);
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = numArrayCreate(nums, sizeof(nums) / sizeof(nums[0]));
    printf("%d\n", numArraySumRange(obj, 1, 4));
    printf("%d\n", numArraySumRange(obj, 2, 5));
    printf("%d\n", numArraySumRange(obj, 0, 5));
    numArrayFree(obj);
}
