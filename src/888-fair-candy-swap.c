#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int sum = 0;
    for (int i = 0; i < ASize; ++i) {
        sum += A[i];
    }
    for (int i = 0; i < BSize; ++i) {
        sum -= B[i];
    }
    int diff = sum / 2;
    *returnSize = 2;
    int *result = malloc(2 * sizeof(int));
    int tmpDiff;
    qsort(A, ASize, sizeof(A[0]), cmp);
    qsort(B, BSize, sizeof(B[0]), cmp);
    for (int i = 0, j = 0; i < ASize && j < BSize;) {
        tmpDiff = A[i] - B[j];
        if (tmpDiff == diff) {
            result[0] = A[i];
            result[1] = B[j];
            return result;
        }
        if (tmpDiff > diff) {
            ++j;
        } else {
            ++i;
        }
    }
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    */
    int A[] = {1, 2, 5};
    int B[] = {2, 4};
    int returnSize;
    int *result = fairCandySwap(A, 3, B, 2, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    free(result);
    return 0;
}
