#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int minMoves2(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int result = 0;
    for (int i = 0, j = numsSize - 1; i < j; ++i, --j) {
        result += nums[j] - nums[i];
    }
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {1, 3, 2, 4, 5, 2, 7, 2, 9};
    printf("%d", minMoves2(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
