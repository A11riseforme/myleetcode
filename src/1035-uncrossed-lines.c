#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int maxUncrossedLines(int* A, int ASize, int* B, int BSize){
    int dp[ASize+1][BSize+1];
    memset(dp, 0, sizeof(dp));
    /*
    int **dp = malloc((ASize+1)*sizeof(int*));
    for (int i = 0; i <= ASize; ++i) {
        dp[i] = calloc(BSize+1, sizeof(int));
    }
    */
    for (int i = 1; i <= ASize; ++i) {
        for (int j = 1; j <= BSize; ++j) {
            dp[i][j] = MAX(MAX(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]+(A[i-1]==B[j-1]));
        }
    }
    return dp[ASize][BSize];
}

int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int A[] = {1,3,7,1,7,5};
    int B[] = {1,9,2,5,1};
    printf("%d", maxUncrossedLines(A, sizeof(A)/sizeof(A[0]), B, sizeof(B)/sizeof(B[0])));
    return 0;
}