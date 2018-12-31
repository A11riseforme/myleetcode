#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElementSlow(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int *result = malloc(findNumsSize * sizeof(int));
    *returnSize = findNumsSize;
    bool found = false;
    // brute force.
    for (int i = 0; i < findNumsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == findNums[i]) {
                for (int k = j + 1; k < numsSize; k++) {
                    if (nums[k] > findNums[i]) {
                        found = true;
                        result[i] = nums[k];
                        break;
                    }
                }
                break;
            }
        }
        if (!found) {
            result[i] = -1;
        }
        found = false;
    }
    return result;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
    int min = nums[0];
    int max = nums[0];
    for (int i = 1; i < numsSize; i++) {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }
    // table[i] = n means in nums, the next greater number of i is n.
    int *table = malloc((max-min+1)*sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        table[nums[i]-min] = -1;
        for (int j = i+1; j < numsSize; j++) {
            if (nums[j] > nums[i]) {
                table[nums[i]-min] = nums[j];
                break;
            }
        }
    }
    int *result = malloc(findNumsSize*sizeof(int));
    *returnSize = findNumsSize;
    for (int i = 0; i < findNumsSize; i++) {
        result[i] = table[findNums[i]-min];
    }
    free(table);
    return result;
}


int main() {
    int findNums[] = {4, 1, 2};
    int nums[] = {1, 3, 4, 2};
    int returnSize;
    int *result = nextGreaterElement(findNums, 3, nums, 4, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
}
