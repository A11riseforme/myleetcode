#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool isOneBitCharacter(int* bits, int bitsSize) {
    int i = 0;
    while (i < bitsSize - 1) {
        if (bits[i] == 0) {
            i += 1;
        } else {
            i += 2;
        }
    }
    return i == bitsSize - 1;
}

int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test stringA stringB...\n");
        exit(-1);
    }
    */
    int bits[] = {1, 1, 1, 0};
    printf("%s\n", isOneBitCharacter(bits, sizeof(bits) / sizeof(bits[0])) ? "yes" : "no");
    return 0;
}
