#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int largestPerimeter(int* A, int ASize) {
    qsort(A, ASize, sizeof(A[0]), cmp);
    for (int i = 0; i < ASize - 2; ++i) {
        if (A[i + 2] + A[i + 1] > A[i]) {
            return A[i] + A[i + 1] + A[i + 2];
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {3, 6, 2, 3};
    printf("%d", largestPerimeter(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
