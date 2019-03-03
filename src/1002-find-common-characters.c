#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b))?(b):(a)

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** commonChars(char** A, int ASize, int* returnSize) {
    int **freq = malloc(ASize * sizeof(int*));
    for (int i = 0; i < ASize; ++i) {
        freq[i] = calloc(26, sizeof(int));
        for (int j = 0; A[i][j] != '\0'; ++j) {
            ++freq[i][A[i][j] - 'a'];
        }
    }
    char **result = malloc(100 * sizeof(char*));
    *returnSize = 0;
    int n = 0;
    for (int i = 0; i < 26; ++i) {
        int tmp = INT_MAX;
        for (int j = 0; j < ASize; ++j) {
            tmp = MIN(tmp, freq[j][i]);
        }
        for (int k = 0; k < tmp; ++k) {
            result[n] = malloc(2 * sizeof(char));
            result[n][0] = i + 'a';
            result[n++][1] = '\0';
        }
    }
    *returnSize = n;
    for (int i = 0; i < ASize; ++i) {
        free(freq[i]);
    }
    free(freq);
    return result;
}


int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: ./test string1 string2 string3...\n");
        exit(-1);
    }

    char **A = malloc((argc - 1) * sizeof(char*));
    for (int i = 0; i < argc - 1; ++i) {
        A[i] = argv[i + 1];
    }
    int returnSize;
    char **result = commonChars(A, argc - 1, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s ", result[i]);
    }
    return 0;
}
