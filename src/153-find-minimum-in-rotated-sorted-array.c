#include <stdio.h>

int findMin(int* nums, int numsSize) {
    int start = 1;
    int end = numsSize - 1;
    int min = nums[0];
    while (start <= end) {
        int mid = (end + start) / 2;
        min = min < nums[mid] ? min : nums[mid];
        if (nums[mid] > nums[end]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return min;
}


int main() {
    int nums[6] = {5,6,1,2,3,4};
    int test[] = {1,2,3,4,5,6,7,8,9};
    int min = findMin(nums, 6);
    printf("%d", min);
}
