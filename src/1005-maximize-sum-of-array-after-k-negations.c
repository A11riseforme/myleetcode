#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int largestSumAfterKNegations(int* A, int ASize, int K) {
    qsort(A, ASize, sizeof(A[0]), cmp);
    int result = 0;
    for (int i = 0; i < ASize; ++i) {
        if (A[i] >= 0 || K == 0) {
            break;
        }
        A[i] *= -1;
        --K;
    }
    qsort(A, ASize, sizeof(A[0]), cmp);
    for (int i = 0; i < ASize; ++i) {
        result += A[i];
    }
    if (K % 2) {
        return result - 2 * A[0];
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {2, -3, -1, 5, -4};
    int k = 2;
    printf("%d\n", largestSumAfterKNegations(nums, sizeof(nums) / sizeof(nums[0]), k));
    return 0;
}
