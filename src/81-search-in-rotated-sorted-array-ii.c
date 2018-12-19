#include <stdio.h>
#include <stdbool.h>

bool search(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return true;
        }
    }
    return false;
}

int main() {
    int nums[] = {2,5,6,0,0,1,2};
    int target = 0;
    if (search(nums, 7, target)) {
        printf("%d is found in nums[]", target);
    } else {
        printf("%d is not found in nums[]", target);
    }
}
