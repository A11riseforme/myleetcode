#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int hammingWeight(uint32_t n) {
    int result = 0;
    while (n != 0) {
        result += (n % 2);
        n /= 2;
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%d\n", hammingWeight(atoi(argv[1])));
    return 0;
}
