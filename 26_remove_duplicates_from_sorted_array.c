#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int count = 0;
    int newSize = numsSize;
    for(int i = 0; i < numsSize - 1; i++) {
        if(nums[i] == nums[1 + i]) {
            count++;
            newSize--;
        } else {
            nums[i + 1 - count] = nums[i + 1];
        }
    }
    return newSize;
}


int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int n = 10;
    n = removeDuplicates(nums, n);
    printf("%d\n",n);
    for (int i = 0; i < n; i++) {
        printf("%d ",nums[i]);
    }
}
