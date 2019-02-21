#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b))?(b):(a)

char* getHint(char* secret, char* guess) {
    char *result = malloc(20 * sizeof(char));
    int bull = 0, cow = 0;
    int *freq1 = calloc(10, sizeof(int));
    int *freq2 = calloc(10, sizeof(int));
    for (int i = 0; secret[i] != '\0'; ++i) {
        if (secret[i] == guess[i]) {
            ++bull;
        } else {
            ++freq1[secret[i] - '0'];
            ++freq2[guess[i] - '0'];
        }
    }
    for (int i = 0; i < 10; ++i) {
        cow += MIN(freq1[i], freq2[i]);
    }
    sprintf(result, "%dA%dB", bull, cow);
    free(freq1);
    free(freq2);
    return result;
}


int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test secret guess\n");
        exit(-1);
    }
    char *result = getHint(argv[1], argv[2]);
    printf("%s\n", result);
    free(result);
    return 0;
}
