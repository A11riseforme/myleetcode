#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool wordBreak(char* s, char** wordDict, int wordDictSize) {
    int len1 = strlen(s);
    int len2 = len1 + 1;

    bool *matched = calloc(len2, sizeof(bool));
    matched[0] = true;
    for (int i = 0; i < len2; i++) {
        for (int k = 0; k < wordDictSize; k++) {
            if(matched[i]) {
                if(strncmp(s + i, wordDict[k], strlen(wordDict[k])) == 0) {
                    matched[i + strlen(wordDict[k])] = true;
                }
            }
        }
    }
    return matched[len2 - 1];
}


int main(void) {
    char *s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    char **wordDict = calloc(10, sizeof(char *)); //{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    *(wordDict + 0) = "a";
    *(wordDict + 1) = "aa";
    *(wordDict + 2) = "aaa";
    *(wordDict + 3) = "aaaa";
    *(wordDict + 4) = "aaaaa";
    *(wordDict + 5) = "aaaaaa";
    *(wordDict + 6) = "aaaaaaa";
    *(wordDict + 7) = "aaaaaaaa";
    *(wordDict + 8) = "aaaaaaaaa";
    *(wordDict + 9) = "aaaaaaaaaa";
    if (wordBreak(s, wordDict, 10)) {
        printf("yes");
    } else {
        printf("no");
    }
}
