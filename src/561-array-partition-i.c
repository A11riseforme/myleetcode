#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int arrayPairSum(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int result = 0;
    for (int i = 0; i < numsSize; i += 2) {
        result += nums[i];
    }
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int nums[] = {1, 4, 3, 2};
    printf("%d\n", arrayPairSum(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}