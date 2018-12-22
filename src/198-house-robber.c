#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int rob(int* nums, int numsSize) {
    int *money = calloc(numsSize, sizeof(int));
    money[0] = nums[0];
    money[1] = max(nums[0], nums[1]);
    for(int i = 2; i < numsSize; i++) {
        money[i] = max(nums[i] + money[i - 2], money[i - 1]);
    }
    int result = money[numsSize - 1];
    free(money);
    return result;
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
