#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a , const void *b) {
    return *(int *)a - *(int *)b;
}


// modified the array, not meeting qn requirement. =(
int findDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(*nums), cmp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return nums[i];
        }
    }
    return 0;
}

// Floyd's Tortoise and Hare(cycle detection) algorithm.
int findDuplicate(int* nums, int numsSize) {
    if (numsSize > 1) {
        // 快慢指针
        int slow = nums[0]; // 慢指针
        int fast = nums[nums[0]]; // 快指针
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        // 快慢指针相遇
        fast = 0; //再来一遍
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
    return -1;
}


int main() {
    int nums[] = {1,3,4,2,2};
    printf("%d", findDuplicate(nums, 5));
}
