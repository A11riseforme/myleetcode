#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isUgly(int num) {
    int divisor;
    if (num < 1) {
        return false;
    }
    while (num > 6) {
        // divisor = x evaluate to be x, and make use of short-circuit evaluation of ||
        if (num % (divisor = 2) == 0 || num % (divisor = 3) == 0 || num % (divisor = 5) == 0) {
            num /= divisor;
            // bypass the next two line.
            continue;
        }
        // if ever reach here
        return false;
    }
    return true;;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    printf("%d is %sugly number", atoi(argv[1]), isUgly(atoi(argv[1])) ? "" : "not ");
    return 0;
}
