#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// copied from 139-word-break.c
bool wordBreakable(char* s, char** wordDict, int wordDictSize) {
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
    bool result = matched[len2 - 1];
    free(matched);
    return result;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    if (!wordBreakable(s, wordDict, wordDictSize)) {
        return NULL;
    }
    char **result = malloc(500 * sizeof(char*));
    helper(s, wordDict, wordDictSize, returnSize, result);
    return result;
}


void helper(char* s, char** wordDict, int wordDictSize, int* returnSize, char** result) {
    int wLen;
    int index[100];
    for (int i = 0; i < wordDictSize; i++) {
        wLen = strlen(wordDict[i]);
        if (strncmp(s, wordDict[i], wLen) == 0) {
            index[0] = i;
            dfs(s + wLen, wordDict, wordDictSize, returnSize, 1, index, result, wLen + 1);
        }
    }
}


void dfs(char* s, char** wordDict, int wordDictSize, int* returnSize, int num, int* index, char** result, int length) {
    if (*s == '\0') {
        result[*returnSize] = malloc(length * sizeof(char));
        int pos = 0;
        for (int i = 0; i < num; i++) {
            for (int j = 0; wordDict[index[i]][j] != '\0'; j++) {
                result[*returnSize][pos++] = wordDict[index[i]][j];
            }
            result[*returnSize][pos++] = ' ';
        }
        result[(*returnSize)++][length - 1] = '\0';
        return;
    }
    int wLen;
    for (int i = 0; i < wordDictSize; i++) {
        wLen = strlen(wordDict[i]);
        if (strncmp(s, wordDict[i], wLen) == 0) {
            index[num] = i;
            dfs(s + wLen, wordDict, wordDictSize, returnSize, num + 1, index, result, length + wLen + 1);
        }
    }
    return;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: ./test word dictionary...\n");
        exit(-1);
    }

    int i, count = 0;
    char **list = wordBreak(argv[1], argv + 2, argc - 2, &count);
    for (i = 0; i < count; i++) {
        printf("%s\n", list[i]);
    }
    for (int i = 0; i < count; i++) {
        free(list[i]);
    }
    free(list);
    return 0;
}
