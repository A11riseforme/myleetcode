#include <stdio.h>
#include <stdlib.h>

void moveZeroes(int* nums, int numsSize) {
    int j = 0;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j += 1;
        }
    }
    while (j < numsSize) {
        nums[j] = 0;
        j += 1;
    }
}


int main() {
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]);
    }
    return 0;
}
