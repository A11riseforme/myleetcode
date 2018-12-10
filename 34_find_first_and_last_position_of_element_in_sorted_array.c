#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;
    if(numsSize == 0) {
        return result;
    }

    int left = 0;
    int right = numsSize - 1;
    int middle;
    bool found = false;

    while (left <= right) {
        middle = (left + right) / 2;
        if (nums[middle] == target) {
            found = true;
            break;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }

    if (found) {
        int pos = middle;
        // find the left most position.
        while (pos >= 0 && nums[pos] == target) {
            pos--;
        }
        result[0] = pos + 1;
        pos = middle;
        // find the right most position.
        while (pos < numsSize && nums[pos] == target) {
            pos++;
        }
        result[1] = pos - 1;
    }
    return result;
}


int main() {
    int nums[] = {5, 7, 7, 8, 8, 8, 8, 8, 10};
    int size;
    int *pos = searchRange(nums, 9, 8, &size);
    printf("size = %d, left most pos = %d, right most pos = %d", size, pos[0], pos[1]);
    free(pos);
}
