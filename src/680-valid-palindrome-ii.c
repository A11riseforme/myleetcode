#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool isValid(char* s, int l, int r) {
    while (l < r) {
        if (s[l++] == s[r--]) {
            continue;
        }
        return false;
    }
    return true;
}
bool validPalindrome(char* s) {
    int sLen = strlen(s);
    for (int l = 0, r = sLen - 1; l < r; ++l, --r) {
        if (s[l] == s[r]) {
            continue;
        } else {
            return isValid(s, l + 1, r) || isValid(s, l, r - 1);
        }
    }
    return true;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }

    printf("%s\n", validPalindrome(argv[1]) ? "yes" : "no");
    return 0;
}
