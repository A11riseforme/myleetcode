#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


int eval(int* nums, int numsSize, int opt) {
    int result = 0;
    for (int i = 0; i < numsSize; ++i) {
        int tmp = opt % 2;
        result += nums[i] * (tmp ? 1 : -1);
        opt /= 2;
    }
    return result;
}

// brute force, time complexity O(2^n) where n <= 20, so still possible
int findTargetSumWays(int* nums, int numsSize, int S) {
    int total = 1 << numsSize;
    int result = 0;
    for (int i = 0; i < total; ++i) {
        if (eval(nums, numsSize, i) == S) {
            ++result;
        }
    }
    return result;
}

// dp method
int findTargetSumWays(int* nums, int numsSize, int S) {
    int sum = 0;
    for (int i = 0; i < numsSize; ++i) {
        sum += nums[i];
    }
    if (sum < S || S < -sum) {
        return 0;
    }
    int offset = sum;
    // dp[i][j]: number of ways of getting (j-offset) using numbers up to index i;
    int **dp = malloc((numsSize+1)*sizeof(int*));
    for (int i = 0; i <= numsSize; ++i) {
        // range from -sum to sum
        // apply offset, from 0 to sum*2
        dp[i] = calloc(2*sum+1, sizeof(int));
    }
    dp[0][offset] = 1;
    for (int i = 0; i < numsSize; ++i) {
        for (int j = nums[i]; j <= 2*sum-nums[i]; ++j) {
            if (dp[i][j]) {
                dp[i+1][j-nums[i]] += dp[i][j];
                dp[i+1][j+nums[i]] += dp[i][j];
            }
        }
    }
    return dp[numsSize][S+offset];

}

int main(int argc, char** argv) {
    /*
    if (argc != 2) {
    fprintf(stderr, "Usage: ./test number ...\n");
    exit(-1);
    }
    */
    int nums[] = {10, 9, 6, 4, 19, 0, 41, 30, 27, 15, 14, 39, 33, 7, 34, 17, 24, 46, 2, 46};
    printf("%d\n", findTargetSumWays(nums, sizeof(nums) / sizeof(nums[0]), 45));
    return 0;
}
