#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    int newSize = numsSize;
    for(int i = 0; i < numsSize; i++) {
        if(nums[i] == val) {
            count++;
            newSize--;
        } else {
			nums[i - count] = nums[i];
        }
    }
    return newSize;
}


int main() {
    int nums[] = {0,1,2,2,3,0,4,2};
    int n = 8;
    n = removeElement(nums, n, 2);
    printf("%d\n",n);
    for (int i = 0; i < n; i++) {
        printf("%d ",nums[i]);
    }
}
