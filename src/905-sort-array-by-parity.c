#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize) {
    int i = 0, j = ASize - 1;
    int *result = malloc(ASize * sizeof(int));
    int k = 0;
    while (i <= j) {
        if (A[k] & 1) {
            result[j--] = A[k++];
        } else {
            result[i++] = A[k++];
        }
    }
    *returnSize = ASize;
    return result;
}


int main(int argc, char** argv) {
    int nums[] = {3, 1, 2, 4};
    int returnSize;
    int *result = sortArrayByParity(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
