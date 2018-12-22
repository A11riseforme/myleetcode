#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
    int sFreq[128];
    int tFreq[128];
    int i;
    for (i = 0; i < 128; i++) {
        sFreq[i] = tFreq[i] = -1;
    }
    for (i = 0; s[i] != '\0'; i++) {
        if (sFreq[s[i]] == -1 && tFreq[t[i]] == -1) {
            sFreq[s[i]] = t[i];
            tFreq[t[i]] = s[i];
        } else {
            if (sFreq[s[i]] != t[i] || tFreq[t[i]] != s[i]) {
                return false;
            }
        }
    }
    if (t[i] != '\0') {
        return false;
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2\n");
        exit(-1);
    }

    printf("%s and %s are %sisomorphic", argv[1], argv[2], isIsomorphic(argv[1], argv[2]) ? "" : "not ");
    return 0;
}
