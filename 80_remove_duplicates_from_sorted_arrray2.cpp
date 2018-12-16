#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int index = 0;
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && i < numsSize - 1 && nums[i-1] == nums[i] && nums[i] == nums[i+1]) {
            continue;
        }
        nums[index++] = nums[i];
    }
    return index;
}

int main() {
    int nums[] = {1,1,1,2,2,2,3,4,7,8,8,8,9};
    int n = removeDuplicates(nums, sizeof(nums)/sizeof(int));
    for (int i = 0; i < n; i++) {
        printf("%d ",nums[i]);
    }
}
