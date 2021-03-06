#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int smallestRepunitDivByK(int K) {
    bool *remainders = calloc(K, sizeof(bool));
    int remainder = 1 % K;
    remainders[remainder] = true;
    int result = 1;
    while (remainder) {
        ++result;
        remainder = (remainder * 10 + 1) % K;
        if (remainders[remainder]) {
            break;
        }
        remainders[remainder] = true;
    }
    free(remainders);
    if (remainder) {
        return -1;
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    printf("%d\n", smallestRepunitDivByK(atoi(argv[1])));
    return 0;
}