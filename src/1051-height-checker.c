#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;
    return (arg1 > arg2) - (arg1 < arg2);
}

int heightChecker(int *heights, int heightsSize) {
    int *ref = malloc(heightsSize * sizeof(int));
    for (int i = 0; i < heightsSize; ++i) {
        ref[i] = heights[i];
    }
    qsort(ref, heightsSize, sizeof(ref[0]), cmp);
    int result = 0;
    for (int i = 0; i < heightsSize; ++i) {
        result += (ref[i] != heights[i]);
    }
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int nums[] = {1, 1, 4, 2, 1, 3};
    printf("%d\n", heightChecker(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}