#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int minMoves(int* nums, int numsSize) {
    int sum = 0, min = INT_MAX;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
        min = min > nums[i] ? nums[i] : min;
    }
    return sum - min * numsSize;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {1, 3, 2, 4, 5, 2, 7, 2, 9};
    printf("%d", minMoves(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
