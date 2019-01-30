#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

void dfs(char* s, char** result, int* pos, int index, int count, int* returnSize) {
    if (index == count) {
        result[*returnSize] = malloc((strlen(s) + 1) * sizeof(char));
        memcpy(result[*returnSize], s, strlen(s) + 1);
        ++(*returnSize);
        return;
    }
    s[pos[index]] = tolower(s[pos[index]]);
    dfs(s, result, pos, index + 1, count, returnSize);
    s[pos[index]] = toupper(s[pos[index]]);
    dfs(s, result, pos, index + 1, count, returnSize);
    return;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCasePermutation(char* S, int* returnSize) {
    int count = 0;
    int pos[12];
    for (int i = 0; S[i] != '\0'; ++i) {
        if (isalpha(S[i])) {
            pos[count++] = i;
        }
    }
    int num = (int)pow(2, count);
    char **result = malloc(num * sizeof(char*));
    *returnSize = 0;
    dfs(S, result, pos, 0, count, returnSize);
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }

    int returnSize;
    char **result = letterCasePermutation(argv[1], &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
