#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int firstMissingPositive(int* nums, int numsSize) {
    int tmp;

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1]) {
            tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp - 1] = tmp;
            --i;
        }
    }
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) {
            return i + 1;
        }
    }
    return numsSize + 1;
}

int main() {
    int nums[] = {3, 4, -1, 1};
    printf("%d", firstMissingPositive(nums, 4));
}
