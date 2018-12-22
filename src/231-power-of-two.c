#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfTwo(int n) {
    if (n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    if (n % 2 != 0) {
        return false;
    }
    return isPowerOfTwo(n / 2);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%s is %spower of 2\n", argv[1], isPowerOfTwo(atoi(argv[1])) ? "" : "not ");
    return 0;
}
