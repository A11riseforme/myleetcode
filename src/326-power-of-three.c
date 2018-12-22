#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPowerOfThree(int n) {
    if (n < 1) {
        return false;
    }
    if (n == 1) {
        return true;
    }
    if (n % 3 != 0) {
        return false;
    }
    return isPowerOfThree(n/3);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%s is %spower of 3\n", argv[1], isPowerOfThree(atoi(argv[1])) ? "" : "not ");
    return 0;
}
