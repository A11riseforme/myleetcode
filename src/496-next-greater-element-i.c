#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* findNums, int findNumsSize, int* nums, int numsSize, int* returnSize) {
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
