#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp (const void * a, const void * b) {
    return ( *(int*)a - * (int*)b );
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(citations[0]), cmp);
    int result = 1;
    for (int i = citationsSize - 1; i >= 0; --i, ++result) {
        if (citations[i] < result) {
            break;
        }
    }
    return result - 1;
}

int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int nums[] = {1, 3, 5, 2, 7, 9, 12};
    printf("%d\n", hIndex(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}

