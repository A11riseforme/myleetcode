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
bool* prefixesDivBy5(int* A, int ASize, int* returnSize) {
    bool *result = malloc(ASize * sizeof(bool));
    int init = 0;
    for (int i = 0; i < ASize; ++i) {
        init = init * 2 + A[i];
        result[i] = !(init % 5);
        init %= 5;
    }
    *returnSize = ASize;
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string number ...\n");
        exit(-1);
    }
    */
    int A[] = {0, 1, 1, 1, 1, 1};
    int returnSize;
    bool *result = prefixesDivBy5(A, sizeof(A) / sizeof(A[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i] ? "yes" : "no");
    }
    return 0;
}
