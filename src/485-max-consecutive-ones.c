#include <stdio.h>
#include <stdlib.h>

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        while (nums[i] != 1 && i < numsSize) {
            ++i;
        }
        int start = i;
        while (nums[i] == 1 && i < numsSize) {
            ++i;
        }
        result = i - start > result ? i - start : result;
    }
    return result;
}


int main() {
    int nums[] = {1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1};
    printf("%d", findMaxConsecutiveOnes(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
