#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int longestPalindrome(char* s) {
    int freq[128] = {0};
    for (int i = 0; s[i] != '\0'; ++i) {
        ++freq[s[i]];
    }
    int result = 0;
    for (int i = 0; i < 128; ++i) {
        // length is odd
        if (!(result & 1)) {
            result += freq[i];
            continue;
        }
        result += freq[i]/2*2;
    }
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string \n");
        exit(-1);
    }
    printf("%d", longestPalindrome(argv[1]));
    return 0;
}
