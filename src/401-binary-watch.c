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
char** readBinaryWatch(int num, int* returnSize) {
    char **result = malloc(720 * sizeof(char*));
    int hbits, mbits, hh, mm;
    *returnSize = 0;
    for (int h = 0; h < 12; ++h) {
        hbits = 0;
        hh = h;
        while (hh) {
            hbits += hh & 1;
            hh >>= 1;
        }
        for (int m = 0; m < 60; ++m) {
            mbits = 0;
            mm = m;
            while (mm) {
                mbits += mm & 1;
                mm >>= 1;
            }
            if (mbits + hbits == num) {
                result[*returnSize] = malloc(6 * sizeof(char));
                sprintf(result[(*returnSize)++], "%d:%02d", h, m);
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number...\n");
        exit(-1);
    }

    int returnSize;
    char **result = readBinaryWatch(atoi(argv[1]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
