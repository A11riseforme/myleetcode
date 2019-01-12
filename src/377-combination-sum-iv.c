#include <stdio.h>
#include <stdlib.h>

int combinationSum4(int* nums, int numsSize, int target) {
    int *dp = calloc(target + 1, sizeof(int));
    dp[0] = 1;
    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < numsSize; ++j) {
            if (i - nums[j] >= 0) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}


int main() {
    int nums[] = {1, 2, 3, 4};
    int target = 10;
    printf("%d", combinationSum4(nums, 4, target));
    return 0;
}
