#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int *result = malloc(10001 * sizeof(int));
    int i, j = 0;
    for (i = ASize - 1; i >= 0; --i) {
        result[j++] = (A[i] + K) % 10;
        K = (K + A[i]) / 10;
    }
    while (K > 0) {
        result[j++] = K % 10;
        K /= 10;
    }
    for (int l = 0, r = j - 1; l < r; ++l, --r) {
        result[l] ^= result[r] ^= result[l] ^= result[r];
    }
    *returnSize = j;
    return result;
}

int main(int argc, char **argv) {
    int A[] = {2, 1, 5};
    int K = 806;
    int returnSize;
    int *result = addToArrayForm(A, sizeof(A) / sizeof(A[0]), K, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
}
