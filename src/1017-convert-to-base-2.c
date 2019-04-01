#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

char* baseNeg2(int N) {
    char *result = malloc(100 * sizeof(char));
    if (N == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    int i = 0;
    while (N) {
        int tmp = N & 1;
        //printf("%d\n", tmp);
        result[i++] = tmp + '0';
        N = -(N >> 1);
    }
    for (int l = 0, r = i - 1; l < r;) {
        result[l++] ^= result[r--] ^= result[l] ^= result[r];
    }
    result[i] = '\0';
    return result;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }

    printf("%s\n", baseNeg2(atoi(argv[1])));
    return 0;
}
