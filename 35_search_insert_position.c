#include <stdio.h>

// stupid linear search.
/*
int searchInsert(int* nums, int numsSize, int target) {
    if (nums[0] > target) {
        return 0;
    }
    if (nums[numsSize - 1] < target) {
        return numsSize;
    }
    int i = 0;
    while (i < numsSize) {
        if (nums[i] == target) {
            return i;
        } else if(nums[i] < target && nums[i + 1] > target) {
            return i + 1;
        }
        i += 1;
    }
    return i;
}
*/
int searchInsert(int* nums, int numsSize, int target) {
    int left = 0;
    int right = numsSize - 1;
    int middle;
    while (left <= right) {
        middle = (left + right) / 2;
        if (target == nums[middle]) {
            return middle;
        } else if (target < nums[middle]) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return left;
}


int main() {
    int nums[] = {1,2,3,4,5,7,8,9};
    int pos = searchInsert(nums, 8, 6);
    printf("insert 6 at the position of %d", pos);
}
