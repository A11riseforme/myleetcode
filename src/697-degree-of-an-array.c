#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b))?(b):(a)

#define MAX(a,b) ((a)<(b))?(b):(a)

// sliding window, shrink left and right bound
int findShortestSubArray(int* nums, int numsSize) {
    int freq[50000] = {0};
    int degree = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        ++freq[nums[i]];
        degree = MAX(degree, freq[nums[i]]);
    }
    int result = numsSize;
    int freq1[50000] = {0};
    ++freq1[nums[0]];
    for (int l = 0, r = 1; r < numsSize;) {
        while (freq1[nums[r - 1]] != degree && r < numsSize) {
            ++freq1[nums[r++]];
        }
        while (freq1[nums[r - 1]] == degree) {
            --freq1[nums[l++]];
        }
        result = MIN(r - l + 1, result);
    }
    return result;
}


//record down the left and right index
int findShortestSubArray(int* nums, int numsSize) {
    int freq[50000] = {0};
    int left[50000];
    int right[50000];
    memset(left, 0xff, sizeof(left));
    int degree = INT_MIN;
    for (int i = 0; i < numsSize; ++i) {
        ++freq[nums[i]];
        degree = MAX(degree, freq[nums[i]]);
        if (left[nums[i]] == -1) {
            left[nums[i]] = i;
            right[nums[i]] = i;
        } else {
            right[nums[i]] = i;
        }
    }
    int result = numsSize;
    for (int i = 0; i < numsSize; ++i) {
        if (freq[nums[i]] == degree) {
            result = MIN(result, right[nums[i]] - left[nums[i]] + 1);
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test stringA stringB...\n");
        exit(-1);
    }
    */
    int nums[] = {1, 2, 2, 3, 1};
    printf("%d\n", findShortestSubArray(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
