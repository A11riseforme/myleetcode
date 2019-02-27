#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b)) ? (a) : (b)

int maxTurbulenceSize(int* A, int ASize) {
    if (ASize == 1) {
        return 1;
    }
    int *dp = malloc(ASize * sizeof(int));
    dp[0] = 1;
    dp[1] = (A[1] != A[0] ? 2 : 1);
    int result = MAX(dp[0], dp[1]);
    for (int i = 2; i < ASize; ++i) {
        if ((A[i] > A[i - 1] && A[i - 1] < A[i - 2]) || (A[i] < A[i - 1] && A[i - 1] > A[i - 2])) {
            dp[i] = dp[i - 1] + 1;
        } else if (A[i] != A[i - 1]) {
            dp[i] = 2;
        } else {
            dp[i] = 1;
        }
        result = MAX(dp[i], result);
    }
    free(dp);
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */

    int nums[] = {9, 4, 2, 10, 7, 8, 8, 1, 9};
    printf("%d\n", maxTurbulenceSize(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
