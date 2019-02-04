#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)

int cmp(const int* a, const int* b) {
    return *a > *b;
}

int maximumProduct(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    return MAX(nums[0] * nums[1] * nums[numsSize - 1], nums[numsSize - 3] * nums[numsSize - 2] * nums[numsSize - 1]);
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string \n");
        exit(-1);
    }
    */
    int nums[] = {1, 2, 3, 4};
    printf("%d", maximumProduct(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
