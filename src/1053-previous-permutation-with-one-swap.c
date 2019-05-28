#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *prevPermOpt1(int *a, int ASize, int *returnSize) {
    *returnSize = ASize;
    int swp1 = -1, swp2 = ASize - 1;
    for (int i = ASize - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            swp1 = i;
            break;
        }
    }
    // if ascending, no prev_permutation
    if (swp1 == -1) {
        return a;
    }
    while (a[swp1] <= a[swp2])
        swp2--;
    while (a[swp2 - 1] == a[swp2])
        swp2--;
    a[swp1] ^= a[swp2] ^= a[swp1] ^= a[swp2];

    return a;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int nums[] = {1, 9, 4, 6, 7};
    int returnSize;
    int *result =
        prevPermOpt1(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}