#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParityII(int* A, int ASize, int* returnSize) {
    int *result = malloc(ASize * sizeof(int));
    int evenPos = 0;
    int oddPos = 1;
    for (int i = 0; i < ASize; ++i) {
        // odd number
        if (A[i] & 1) {
            result[oddPos] = A[i];
            oddPos += 2;
            continue;
        }
        result[evenPos] = A[i];
        evenPos += 2;
    }
    *returnSize = ASize;
    return result;
}


int main() {
    int nums[] = {4, 2, 5, 7};
    int returnSize;
    int *result = sortArrayByParityII(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
