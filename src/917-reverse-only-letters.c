#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

char* reverseOnlyLetters(char* S) {
    int l = 0, r = strlen(S) - 1;
    while (l < r) {
        while (!isalpha(S[l])) {
            ++l;
        }
        while (!isalpha(S[r])) {
            --r;
        }
        if (l < r) {
            S[l++] ^= S[r--] ^= S[l] ^= S[r];
        }
    }
    return S;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%s", reverseOnlyLetters(argv[1]));
    return 0;
}
