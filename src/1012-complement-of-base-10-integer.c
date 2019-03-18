#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int bitwiseComplement(int N) {
    int i = 1;
    while (N>i) {
        i = (i << 1) + 1;
    }
    return i-N;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("%d\n", bitwiseComplement(atoi(argv[1])));
    return 0;
}
