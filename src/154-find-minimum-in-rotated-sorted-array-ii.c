#include <stdio.h>

// even linear search would hit 0ms in leetcode.
// why would I implement binary search?
int findMin(int* nums, int numsSize) {
    int min = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min = min < nums[i] ? min : nums[i];
    }
    return min;
}


// here is a sample of binary search.
int findMinBinary(int* nums, int numsSize) {
    //binary search
    int start = 0;
    int end = numsSize - 1;
    int mid = 0;
    while (start < end){
        mid = (end + start)/2;
        if(nums[mid] < nums[end]){
            end = mid;
        } else if (nums[mid] > nums[end]){
            start = mid + 1;
        } else {
            end--;
        }
    }
    return nums[start];
}


int main() {
    int nums[5] = {2,2,2,0,1};
    int min = findMin(nums, 5);
    printf("%d", min);
}
