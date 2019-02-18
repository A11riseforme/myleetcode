#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int dominantIndex(int* nums, int numsSize) {
    if (numsSize == 1) {
        return 0;
    }
    int max1 = INT_MIN;
    int max1Pos = 0;
    int max2 = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] >= max1) {
            max2 = max1;
            max1 = nums[i];
            max1Pos = i;
        } else if (nums[i] > max2) {
            max2 = nums[i];
        }
    }
    return max1 >= max2 * 2 ? max1Pos : -1;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string of parentheses\n");
        exit(-1);
    }
    */
    int nums[] = {3, 6, 1, 0};
    printf("%d\n", dominantIndex(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
