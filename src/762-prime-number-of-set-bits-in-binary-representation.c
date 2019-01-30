#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool isSmallPrime(int n) {
    return n == 2 || n == 3 || n == 5 || n == 7 || n == 11 || n == 13 || n == 17 || n == 19;
}

int countPrimeSetBits(int L, int R) {
    int result = 0, bits;
    for (int i = L; i <= R; i++) {
        bits = 0;
        for (int n = i; n; n >>= 1) {
            bits += n & 1;
        }
        result += isSmallPrime(bits);
    }
    return result;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test left right\n");
        exit(-1);
    }
    printf("%d", countPrimeSetBits(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
