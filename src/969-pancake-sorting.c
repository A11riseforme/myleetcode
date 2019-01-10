#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool issorted(int* nums, int n) {
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            return false;
        }
    }
    return true;
}


void reverse(int* nums, int left, int right) {
    while (left < right) {
        int tmp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = tmp;
    }
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * need 2 flips to sort the unsorted largest number to its right place.
 */
int* pancakeSort(int* A, int ASize, int* returnSize) {
    int *result = malloc(10 * ASize * sizeof(int));
    *returnSize = 0;
    while (!issorted(A, ASize)) {
        for (int i = 0; i < ASize; i++) {
            if (A[i] == ASize) {
                // flip the unsorted largest number to the start pos.
                result[(*returnSize)++] = i + 1;
                reverse(A, 0, i);
                // flip the unsorted largest number to the right place.
                result[(*returnSize)++] = ASize--;
                reverse(A, 0, ASize);
                break;
            }
        }
    }
    return result;
}

int main() {
    int nums[] = {1, 4, 2, 5, 3, 7, 6};
    int returnSize;
    int *result = pancakeSort(nums, 7, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
