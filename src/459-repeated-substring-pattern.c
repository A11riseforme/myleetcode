#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

bool is_prime(long num) {
    if (num == 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    if ((num % 6 != 1) && (num % 6 != 5)) {
        return false;
    }
    for (long i = 5; i <= sqrt(num); i += 6) {
        if ((num % i == 0) || (num % (i + 2) == 0)) {
            return false;
        }
    }
    return true;
}

// slow algorithm.
bool repeatedSubstringPatternSlow(char* s) {
    int sLen = strlen(s);
    if (sLen <= 1) {
        return false;
    }
    int subLen;
    bool matched = true;
    for (int i = 2; i <= sLen; i++) {
        if (is_prime(i)) {
            subLen = sLen % i ? 0 : sLen / i;
            if (subLen == 0) {
                continue;
            }
            for (int j = 1; j < i; j++) {
                if (strncmp(s, s + j * subLen, subLen) != 0) {
                    matched = false;
                    break;
                }
                matched = true;
            }
            if (!matched) {
                continue;
            }
            return true;
        }
    }
    return false;
}

// let S1 be s[1:]+s[:-1], if s in S1, return true.
// else return false
bool repeatedSubstringPattern(char* s) {
    int len = strlen(s);
    char string[20000] = {0};
    memcpy(string, s + 1, len - 1);
    memcpy(string + len - 1, s, len - 1);
    if (!strstr(string, s)) {
        return false;
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%s\n", repeatedSubstringPattern(argv[1]) ? "yes" : "no");
    return 0;
}
