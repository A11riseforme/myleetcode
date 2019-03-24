#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool queryString(char* S, int N) {
    char *bits = malloc(32 * sizeof(char));
    ++N;
    while (N--) {
        int n = N;
        int i = 0;
        while (n) {
            int tmp = n % 2;
            n /= 2;
            bits[i++] = tmp + '0';
        }
        for (int l = 0, r = i - 1; l < r;) {
            bits[l++] ^= bits[r--] ^= bits[l] ^= bits[r];
        }
        bits[i] = '\0';
        if (!strstr(S, bits)) {
            return false;
        }
    }
    return true;
}


int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string number ...\n");
        exit(-1);
    }

    printf("%s", queryString(argv[1], atoi(argv[2])) ? "yes" : "no");
    return 0;
}
