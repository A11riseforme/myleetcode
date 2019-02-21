#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

int smallestRangeI(int* A, int ASize, int K) {
    int min = A[0], max = A[0];
    for (int i = 1; i < ASize; ++i) {
        min = MIN(min, A[i]);
        max = MAX(max, A[i]);
    }
    return MAX(max - min - 2 * K, 0);
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test secret guess\n");
        exit(-1);
    }
    */
    int nums[] = {1, 3, 6};
    printf("%d\n", smallestRangeI(nums, sizeof(nums) / sizeof(nums[0]), 3));
    return 0;
}
