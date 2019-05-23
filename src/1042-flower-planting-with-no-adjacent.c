#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *gardenNoAdj(int N, int **paths, int pathsSize, int *pathsColSize,
                 int *returnSize) {

    int **al = malloc(N * sizeof(int *));
    int *size = calloc(N, sizeof(int));

    for (int i = 0; i < N; ++i) {
        al[i] = malloc(3 * sizeof(int));
    }

    for (int i = 0; i < pathsSize; ++i) {
        int a = paths[i][0] - 1;
        int b = paths[i][1] - 1;
        al[a][size[a]++] = b;
        al[b][size[b]++] = a;
    }
    int *result = calloc(N, sizeof(int));
    result[0] = 1;

    for (int i = 1; i < N; ++i) {
        bool colors[4] = {true, true, true, true};
        int j;
        for (j = 0; j < size[i]; ++j) {
            if (result[al[i][j]]) {
                colors[result[al[i][j]] - 1] = false;
            }
        }

        for (j = 0; !colors[j]; ++j) {
        }
        result[i] = j + 1;
    }

    *returnSize = N;
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    printf("I am too lazy to code the testcases\n");
    return 0;
}