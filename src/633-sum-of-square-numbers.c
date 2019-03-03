#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool judgeSquareSum(int c) {
    long l = 0, r = sqrt(c), sum;
    while (l <= r) {
        sum = l * l + r * r;
        if (sum == c) {
            return true;
        }
        if (sum > c) {
            --r;
        } else {
            ++l;
        }
    }
    return false;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number...\n");
        exit(-1);
    }

    printf("%s\n", judgeSquareSum(atoi(argv[1])) ? "yes" : "no");
    return 0;
}
