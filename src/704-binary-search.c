#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2...\n");
        exit(-1);
    }
    */
    int nums[] = {-1, 0, 3, 5, 9, 12};
    printf("%d\n", search(nums, sizeof(nums) / sizeof(nums[0]), 9));
    return 0;
}
