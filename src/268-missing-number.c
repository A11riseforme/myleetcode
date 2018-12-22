#include <stdio.h>
#include <stdlib.h>

int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    for(int i = 0; i < numsSize; i++) {
        sum += nums[i];
    }
    return (numsSize + 1) * (numsSize) / 2 - sum;
}


int main() {
    int nums[] = {9,6,4,2,3,5,7,0,1};
    printf("%d\n", missingNumber(nums, 9));
    return 0;
}
