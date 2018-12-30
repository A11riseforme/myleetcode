#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char *pos;
    int count;
} tables;


int numMatchingSubseq(char* S, char** words, int wordsSize) {
    // group the same words together.
    tables *wordsTable = calloc(wordsSize, sizeof(tables));
    int diffNum = 0;
    wordsTable[0].pos = words[0];
    wordsTable[0].count = 1;
    diffNum = 1;
    bool dupFound = false;
    for (int i = 1; i < wordsSize; i++) {
        dupFound = false;
        for (int j = 0; j < diffNum; j++) {
            if (strcmp(wordsTable[j].pos, words[i]) == 0) {
                dupFound = true;
                wordsTable[j].count++;
                break;
            }
        }
        if (!dupFound) {
            wordsTable[diffNum].pos = words[i];
            wordsTable[diffNum++].count = 1;
        }
    }
    // waitList record the pos of the char to be paired.
    int *waitList = calloc(diffNum, sizeof(int));
    int result = 0;
    for (int i = 0; S[i] != '\0'; i++) {
        for (int j = 0; j < diffNum; j++) {
            if (waitList[j] == -1) {
                continue;
            }
            if (wordsTable[j].pos[waitList[j]] != S[i]) {
                continue;
            }
            waitList[j]++;
            if (wordsTable[j].pos[waitList[j]] == '\0') {
                result += wordsTable[j].count;
                waitList[j] = -1;
            }
        }
    }
    free(wordsTable);
    return result;
}

int main() {
    char *s = "abcde";
    char **words = malloc(4*sizeof(char*));
    words[0] = "a";
    words[1] = "bb";
    words[2] = "acd";
    words[3] = "ace";
    printf("%d", numMatchingSubseq(s, words, 4));
    free(words);
}
