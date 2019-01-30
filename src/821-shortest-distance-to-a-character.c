#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char* S, char C, int* returnSize) {
    int len = strlen(S);
    int *result = malloc(len * sizeof(int));
    int tmp[10000];
    int min, n = 0;
    for (int i = 0; i < len; ++i) {
        if (S[i] == C) {
            tmp[n++] = i;
        }
    }
    for (int i = 0; i < len; ++i) {
        if (S[i] == C) {
            result[i] = 0;
        } else {
            min = INT_MAX;
            for (int j = 0; j < n; ++j) {
                min = min > abs(tmp[j] - i) ? abs(tmp[j] - i) : min;
            }
            result[i] = min;
        }
    }
    *returnSize = len;
    return result;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string char\n");
        exit(-1);
    }
    int returnSize;
    int *result = shortestToChar(argv[1], argv[2][0], &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
