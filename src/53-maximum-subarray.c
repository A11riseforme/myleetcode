#include <stdlib.h>

//brute force
int maxSubArraySlow(int* nums, int numsSize) {
    int max = nums[0];
    int sum = 0;
    for (int i = 0; i < numsSize; i++) {
        sum = 0;
        for (int j = i; j < numsSize; j++) {
            sum += nums[j];
            max = (sum > max) ? sum : max;
        }
    }
    return max;
}


//dp
int maxSubArray(int* nums, int numsSize) {
    int max = nums[0];
    int sum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        sum = sum > 0 ? sum + nums[i] : nums[i];
        max = sum > max ? sum : max;
    }
    return max;
}


int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int result = maxSubArray(nums, 9);
    printf("%d",result);
}
