#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * using extra space. =(
 */
int* findDuplicatesExtraSpace(int* nums, int numsSize, int* returnSize) {
    int *freq = calloc(numsSize, sizeof(int));
    int *result = calloc(numsSize, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        if (freq[nums[i] - 1] != 0) {
            result[(*returnSize)++] = nums[i];
        }
        freq[nums[i] - 1]++;
    }
    return result;
}


void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * without using extra space.
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        // if nums[i] is not at the right pos.
        if (nums[i] != nums[nums[i] - 1]) {
            swap(&nums[i], &nums[nums[i] - 1]);
            i--;
        }
    }
    int *result = calloc(numsSize, sizeof(int*));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        //printf("%d", nums[i]);
        if (nums[i] != i + 1) {
            result[(*returnSize)++] = nums[i];
        }
    }
    return result;
}


int main() {
    int nums[] = {39, 31, 8, 14, 14, 38, 5, 15, 29, 49, 18, 6, 30, 47, 8, 35, 2, 17, 6, 10, 29, 46, 41, 48, 1, 36, 5, 28, 46, 39, 7, 47, 18, 42, 17, 11, 36, 45, 21, 33, 24, 10, 24, 50, 25, 16, 9, 12, 11, 25};
    int returnSize;;
    int *result = findDuplicates(nums, 50, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
