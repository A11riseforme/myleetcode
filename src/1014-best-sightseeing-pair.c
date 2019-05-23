#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b)
int maxScoreSightseeingPair(int *A, int ASize) {
    int *diff = malloc(ASize * sizeof(int));
    int *sum = malloc(ASize * sizeof(int));
    for (int i = 0; i < ASize; ++i) {
        diff[i] = A[i] - i;
        sum[i] = A[i] + i;
    }
    int maxi = sum[0];
    for (int i = 1; i < ASize; ++i) {
        maxi = MAX(maxi, sum[i]);
        sum[i] = maxi;
    }
    maxi = diff[ASize - 1];
    for (int i = ASize - 2; i >= 0; --i) {
        maxi = MAX(maxi, diff[i]);
        diff[i] = maxi;
    }
    int result = INT_MIN;
    for (int i = 0; i < ASize - 1; ++i) {
        result = MAX(result, sum[i] + diff[i + 1]);
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
    int A[] = {8, 1, 5, 2, 6};
    printf("%d\n", maxScoreSightseeingPair(A, sizeof(A) / sizeof(A[0])));
    return 0;
}