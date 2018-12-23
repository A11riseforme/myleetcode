#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

// copy from the solution of 198. House Robber
int robNoRestriction(int* nums, int numsSize) {
    int *money = (int *)calloc(numsSize, sizeof(int));
    money[0] = nums[0];
    money[1] = max(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++) {
        money[i] = max(nums[i] + money[i - 2], money[i - 1]);
    }
    int result = money[numsSize - 1];
    free(money);
    return result;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[0];
    }
    return max(robNoRestriction(nums, numsSize - 1), robNoRestriction(nums + 1, numsSize - 1));
}


int main(int argc, char **argv) {
    int i, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%d\n", rob(nums, count));
    free(nums);
    return 0;
}
