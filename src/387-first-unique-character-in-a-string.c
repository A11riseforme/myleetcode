#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int firstUniqChar(char* s) {
    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; ++i) {
        ++freq[s[i] - 'a'];
    }
    for (int i = 0; s[i] != '\0'; ++i) {
        if (freq[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }

    printf("%d\n", firstUniqChar(argv[1]));
    return 0;
}
