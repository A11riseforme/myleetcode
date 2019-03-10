#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int fact(int n) {
    if (n >= 3) {
        return n * (n - 1) / (n - 2);
    }
    if (n == 2) {
        return 2;
    }
    if (n == 0) {
        return 0;
    }
    return 1;
}

int clumsy(int n) {
    int result = fact(n);
    n -= 3;
    while (n >= 1) {
        result += n--;
        result -= fact(n);
        n -= 3;
    }
    return result;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("%d\n", clumsy(atoi(argv[1])));
    return 0;
}
