#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


char findTheDifferenceSmarter(char* s, char* t) {
    char result = 0;
    int i = 0;
    while (s[i]) {
        result ^= s[i++];
    }
    i = 0;
    while(t[i]) {
        result ^= t[i++];
    }
    return result;
}


char findTheDifference(char* s, char* t) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; ++i) {
        ++freq[s[i] - 'a'];
    }
    for (int i = 0; t[i] != '\0'; ++i) {
        if (freq[t[i] - 'a'] == 0) {
            return t[i];
        }
        --freq[t[i] - 'a'];
    }
    return 'a';
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2\n");
        exit(-1);
    }
    printf("%c", findTheDifference(argv[1], argv[2]));
    return 0;
}
