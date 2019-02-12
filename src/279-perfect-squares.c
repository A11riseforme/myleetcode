#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int numSquares(int n) {
    while (n % 4 == 0) {
        n /= 4;
    }
    if (n % 8 == 7) {
        return 4;
    }
    for (int i = 0; i * i <= n; ++i) {
        int j = sqrt(n - i * i);
        if (i * i + j * j == n) {
            return (i > 0) + (j > 0);
        }
    }
    return 3;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("%d", numSquares(atoi(argv[1])));
    return 0;
}
