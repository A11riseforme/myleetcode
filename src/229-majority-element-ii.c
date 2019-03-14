#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        return NULL;
    }
    int a, cnta, b, cntb;
    cnta = cntb = 0;
    a = b = nums[0];
    for (int i = 0; i < numsSize; ++i) {
        if (a == nums[i]) {
            ++cnta;
            continue;
        }
        if (b == nums[i]) {
            ++cntb;
            continue;
        }
        if (cnta == 0) {
            a = nums[i];
            ++cnta;
            continue;
        }
        if (cntb == 0) {
            b = nums[i];
            ++cntb;
            continue;
        }
        --cnta;
        --cntb;
    }
    cnta = cntb = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == a) {
            ++cnta;
            continue;
        }
        if (nums[i] == b) {
            ++cntb;
            continue;
        }
    }
    int *result = malloc(2 * sizeof(int));
    *returnSize = 0;
    if (cnta > numsSize / 3) {
        result[(*returnSize)++] = a;
    }
    if (cntb > numsSize / 3) {
        result[(*returnSize)++] = b;
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {1, 1, 1, 3, 3, 2, 2, 2};
    int returnSize = 0;
    int *result = majorityElement(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
