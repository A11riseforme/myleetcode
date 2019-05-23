#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>、

#define MIN(a, b) ((a) > (b)) ? (b) : (a)
#define MAX(a, b) ((a) > (b)) ? (a) : (b)

int shipWithinDays(int *weights, int weightsSize, int D) {
    // minimum capacity should be at least the largest element of weights,
    // otherwise that element will never be loaded.
    int mini = weights[0];
    // maximum capacity is the sum of the weights, so they will be shipped
    // within one day.
    int maxi = weights[0];
    for (int i = 1; i < weightsSize; ++i) {
        mini = MAX(mini, weights[i]);
        maxi += weights[i];
    }
    int mid;
    int cnt;
    int sum;
    while (maxi > mini) {
        mid = (maxi + mini) / 2;
        sum = cnt = 0;
        for (int i = 0; i < weightsSize; ++i) {
            sum += weights[i];
            if (sum > mid) {
                sum = 0;
                ++cnt;
                --i;
            }
        }
        ++cnt;
        if (cnt > D) {
            mini = mid + 1;
        } else {
            maxi = mid;
        }
    }
    return mini;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n",
           shipWithinDays(weights, sizeof(weights) / sizeof(weights[0]), 15));
    return 0;
}