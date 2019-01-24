#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int tmp;
    for (int i = 0; i < numsSize; ++i) {
        // move the number to where it should be.1 should be at 0st pos.
        if (nums[i] != nums[nums[i] - 1]) {
            tmp = nums[i];
            nums[i] = nums[nums[i] - 1];
            nums[tmp - 1] = tmp;
            --i;
        }
    }

    int *result = malloc(numsSize * sizeof(int));
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != i + 1) {
            result[(*returnSize)++] = i + 1;
        }
    }
    return result;
}

int main() {
    int nums[] = {4, 3, 2, 7, 8, 2, 3, 1};
    int returnSize = 0;
    int *result = findDisappearedNumbers(nums, 8, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
}
