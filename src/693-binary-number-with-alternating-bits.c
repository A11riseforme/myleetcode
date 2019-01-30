#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

bool hasAlternatingBits(int n) {
    for (; n; n >>= 1) {
        if (!(n % 2 ^ (n >> 1) % 2)) {
            return false;
        }
    }
    return true;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    printf("%s", hasAlternatingBits(atoi(argv[1])) ? "yes" : "no");
    return 0;
}
