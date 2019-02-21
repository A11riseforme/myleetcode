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
    int *freq = calloc(10, sizeof(int));
    for (int i = 0; secret[i] != '\0'; ++i) {
        if (secret[i] == guess[i]) {
            ++bull;
        } else {
            if (freq[secret[i] - '0'] > 0) {
                ++cow;
            }
            if (freq[guess[i] - '0'] < 0) {
                ++cow;
            }
            --freq[secret[i] - '0'];
            ++freq[guess[i] - '0'];
        }
    }
    sprintf(result, "%dA%dB", bull, cow);
    free(freq);
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
