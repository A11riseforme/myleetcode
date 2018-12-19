#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int sum = nums[0];
    for (int i = 1; i < numsSize; sum ^= nums[i], i++) {} ;
    return sum;
}


int main(void) {
    int nums[] = {4,1,2,1,2};
    printf("The single number is %d", singleNumber(nums, 5));
}
