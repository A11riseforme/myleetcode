#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool check(char *a, char *b, int *score) {
    while (*a != '\0' && *b != '\0') {
        if (score[*a - 'a'] > score[*b - 'a']) {
            return false;
        }
        if (score[*a++ - 'a'] < score[*b++ - 'a']) {
            return true;
        }
    }
    if (*a != '\0' && *b == '\0') {
        return false;
    }
    return true;
}


bool isAlienSorted(char** words, int wordsSize, char* order) {
    int score[26] = {0};
    for (int i = 0; i < 26; i++) {
        score[order[i] - 'a'] += i;
    }
    for (int i = 0; i < wordsSize - 1; i++) {
        if (!check(words[i], words[i + 1], score)) {
            return false;
        }
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: ./test order word1 word2 ....\n");
        exit(-1);
    }
    int wordsSize = argc - 2;
    char **words = malloc(wordsSize * sizeof(char*));
    for (int i = 0; i < wordsSize; i++) {
        words[i] = argv[i + 2];
    }
    printf("%s", isAlienSorted(words, wordsSize, argv[1]) ? "yes" : "no");
    free(words);
    return 0;
}
