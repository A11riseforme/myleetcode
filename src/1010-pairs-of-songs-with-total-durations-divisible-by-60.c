#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numPairsDivisibleBy60(int *time, int timeSize) {
    int remainders[60] = {0};
    for (int i = 0; i < timeSize; ++i) {
        ++remainders[time[i] % 60];
    }
    int result = 0;
    result += remainders[0] * (remainders[0] - 1) / 2;
    result += remainders[30] * (remainders[30] - 1) / 2;
    for (int l = 1; l < 30; ++l) {
        result += remainders[l] * remainders[60 - l];
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
    int time[] = {30, 20, 150, 100, 40};
    printf("%d\n", numPairsDivisibleBy60(time, sizeof(time) / sizeof(time[0])));
    return 0;
}