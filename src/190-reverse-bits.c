#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t reverseBits(uint32_t n) {
    int result = 0;
    for (int i = 0; i < 32; i += 1) {
        result += (n % 2) * pow(2, 31 - i);
        n /= 2;
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%u\n", reverseBits(atoi(argv[1])));
    return 0;
}
