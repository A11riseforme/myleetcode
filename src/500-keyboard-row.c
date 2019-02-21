#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** words, int wordsSize, int* returnSize) {
    int lines[26] = {2, 1, 1, 2, 3, 2, 2, 2, 3, 2, 2, 2, 1, 1, 3, 3, 3, 3, 2, 3, 3, 1, 3, 1, 3, 1};
    char **result = malloc(wordsSize * sizeof(char*));
    bool onerow;
    *returnSize = 0;
    for (int i = 0; i < wordsSize; ++i) {
        onerow = true;
        for (int j = 1; words[i][j] != '\0'; ++j) {
            if (lines[tolower(words[i][j]) - 'a'] != lines[tolower(words[i][j - 1]) - 'a']) {
                onerow = false;
                break;
            }
        }
        if (onerow) {
            //printf("%s\n", words[i]);
            result[*returnSize] = malloc(100 * sizeof(char));
            strcpy(result[(*returnSize)++], words[i]);
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test secret guess\n");
        exit(-1);
    }
    */
    char **words = malloc(4 * sizeof(char*));
    words[0] = "HellO";
    words[1] = "Alaska";
    words[2] = "Dad";
    words[3] = "Peace";
    int returnSize;
    char **result = findWords(words, 4, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
