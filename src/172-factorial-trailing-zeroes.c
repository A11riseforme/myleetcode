#include <stdio.h>
#include <stdlib.h>

// there are more 2s than 5s, so just need to count number of 5s.
int trailingZeroes(int n) {
    return n == 0 ? 0 : (n / 5) + trailingZeroes(n / 5);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%d\n", trailingZeroes(atoi(argv[1])));
    return 0;
}
