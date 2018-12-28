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

int main() {
    int nums[] = {1,3,4,2,2};
    printf("%d", findDuplicate(nums, 5));
}
