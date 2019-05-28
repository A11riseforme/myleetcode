#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val;
    int cnt;
} tables;

int cmp(const void *a, const void *b) {
    return ((tables *)b)->cnt - ((tables *)a)->cnt;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *rearrangeBarcodes(int *barcodes, int barcodesSize, int *returnSize) {
    tables *freq = malloc(10001 * sizeof(tables));
    int *result = malloc(barcodesSize * sizeof(int));
    *returnSize = barcodesSize;
    for (int i = 0; i < 10000; ++i) {
        freq[i].val = i;
        freq[i].cnt = 0;
    }
    for (int i = 0; i < barcodesSize; ++i) {
        ++freq[barcodes[i]].cnt;
    }
    qsort(freq, 10000, sizeof(*freq), cmp);
    int n = 0;
    for (int i = 0; freq[i].cnt; ++i) {
        for (int j = 0; j < freq[i].cnt; ++j) {
            result[n] = freq[i].val;
            n += 2;
            if (n > barcodesSize - 1) {
                n = 1;
            }
        }
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
    int nums[] = {1, 1, 1, 1, 2, 2, 3, 3};
    int returnSize;
    int *result =
        rearrangeBarcodes(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}