#include <stdio.h>
#include <stdlib.h>

int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize <= 0) {
        return 0;
    }
    int result = 1;
    int start = 0;
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] <= nums[i - 1]) {
            result = i - start > result ? i - start : result;
            start = i;
        }
    }
    if (nums[numsSize - 1] > nums[numsSize - 2]) {
        result = numsSize - start > result ? numsSize - start : result;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test n1 n2 n3...\n");
        exit(-1);
    }
    int numsSize = argc - 1;
    int *nums = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        nums[i] = atoi(argv[i + 1]);
    }

    printf("%d", findLengthOfLCIS(nums, numsSize));
    free(nums);
}
