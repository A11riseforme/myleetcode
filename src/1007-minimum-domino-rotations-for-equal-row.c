#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)<(b))?(a):(b)

int minDominoRotations(int* A, int ASize, int* B, int BSize) {
    bool *appear = malloc(7 * sizeof(bool));
    memset(appear, true, 7);
    int *flipA = calloc(7, sizeof(int));
    int *flipB = calloc(7, sizeof(int));
    for (int i = 0; i < ASize; ++i) {
        if (A[i] == B[i]) {
            for (int j = 1; j <= 6; ++j) {
                if (appear[j]) {
                    if (j != A[i]) {
                        appear[j] = false;
                    }
                }
            }
        } else {
            ++flipB[B[i]];
            ++flipA[A[i]];
            for (int j = 1; j <= 6; ++j) {
                if (appear[j]) {
                    if (j != A[i] && j != B[i]) {
                        appear[j] = false;
                    }
                }
            }
        }
    }
    int result = INT_MAX;
    bool found = false;
    for (int i = 1; i <= 6; ++i) {
        if (appear[i]) {
            found = true;
            result = MIN(result, flipA[i]);
            result = MIN(result, flipB[i]);
        }
    }
    free(appear);
    free(flipA);
    free(flipB);
    if (found) {
        return result;
    }
    return -1;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int A[] = {2, 1, 2, 4, 2, 2};
    int B[] = {5, 2, 6, 2, 3, 2};
    printf("%d\n", minDominoRotations(A, sizeof(A) / sizeof(A[0]), B, sizeof(B) / sizeof(B[0])));
    return 0;
}
