#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** allCellsDistOrder(int R, int C, int r0, int c0, int** columnSizes, int* returnSize) {
    int **result = malloc(R * C * sizeof(int*));
    *columnSizes = malloc(R * C * sizeof(int));
    *returnSize = 0;
    int d = MAX(r0, R - r0 - 1) + MAX(c0, C - c0 - 1);
    for (int i = 0; i <= d; ++i) {
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (abs(r - r0) + abs(c - c0) == i) {
                    result[*returnSize] = malloc(2 * sizeof(int));
                    result[*returnSize][0] = r;
                    result[*returnSize][1] = c;
                    (*columnSizes)[(*returnSize)++] = 2;
                }
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int* columnSizes;
    int returnSize;
    int** result = allCellsDistOrder(2, 3, 1, 2, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(columnSizes);
    free(result);
    return 0;
}

