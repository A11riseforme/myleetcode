#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool canConstruct(char* ransomNote, char* magazine) {
    int freq[26] = {0};
    while (*magazine) {
        ++freq[*magazine - 'a'];
        ++magazine;
    }
    while (*ransomNote) {
        if (freq[*ransomNote - 'a'] == 0) {
            return false;
        }
        --freq[*ransomNote - 'a'];
        ++ransomNote;
    }
    return true;
}


int main(int argc, char** argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test ransomNote magazine \n");
        exit(-1);
    }

    printf("%s", canConstruct(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
