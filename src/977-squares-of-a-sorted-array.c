#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* A, int ASize, int* returnSize) {
    int k = ASize - 1;
    int  *result = malloc(ASize * sizeof(int));
    int i = 0;
    int j = ASize - 1;
    while (i <= j) {
        if (A[i]*A[i] > A[j]*A[j]) {
            result[k--] = A[i] * A[i];
            i++;
            continue;
        }
        result[k--] = A[j] * A[j];
        j--;
    }
    *returnSize = ASize;
    return result;
}


int main(int argc, char** argv) {
    int nums[] = {-7, -3, 2, 3, 11};
    int returnSize;
    int *result = sortedSquares(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
