#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int freq[26] = {0};
    int i;
    for (i = 0; s[i] != '\0' && t[i] != '\0'; i += 1) {
        freq[s[i] - 'a'] += 1;
        freq[t[i] - 'a'] -= 1;
    }
    if ((s[i] == '\0' && t[i] != '\0') || (t[i] == '\0' && s[i] != '\0')) {
        return false;
    }
    for (i = 0; i < 26; i += 1) {
        if (freq[i] != 0) {
            return false;
        }
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2\n");
        exit(-1);
    }

    printf("%s and %s are %sanagrams\n", argv[1], argv[2], isAnagram(argv[1], argv[2]) ? "" : "not ");
    return 0;
}
