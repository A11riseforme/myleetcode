#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largeGroupPositions(char* S, int** columnSizes, int* returnSize) {
    int **result = malloc(350 * sizeof(int*));
    *returnSize = 0;
    *columnSizes = (int*)malloc(350 * sizeof(int));
    for (int l = 0, r = 0; S[r] != '\0';) {
        char curr = S[l];
        while (S[r] == curr && S[r] != '\0') {
            ++r;
        }
        //printf("%d %d\n", l, r);
        if (r - l >= 3) {
            result[*returnSize] = malloc(2 * sizeof(int));
            (*columnSizes)[*returnSize] = 2;
            result[*returnSize][0] = l;
            result[(*returnSize)++][1] = r - 1;
        }
        l = r;
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }
    int *columnSizes;
    int returnSize;
    int **result = largeGroupPositions(argv[1], &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d %d\n", result[i][0], result[i][1]);
        free(result[i]);
    }
    free(columnSizes);
    free(result);
    return 0;
}
