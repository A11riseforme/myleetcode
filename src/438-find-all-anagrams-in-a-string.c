#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isAnna(char *s, char *p) {
    // printf("s = %s, p = %s\n", s, p);
    int *sfreq = calloc(128, sizeof(int));
    for (int i = 0; p[i] != '\0'; ++i) {
        ++sfreq[s[i] - 'a'];
    }
    for (int i = 0; p[i] != '\0'; ++i) {
        if (sfreq[p[i] - 'a'] == 0) {
            free(sfreq);
            return false;
        }
        --sfreq[p[i] - 'a'];
    }
    free(sfreq);
    return true;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findAnagrams(char *s, char *p, int *returnSize) {
    int pLen = strlen(p);
    int sLen = strlen(s);
    if (pLen > sLen) {
        return NULL;
    }
    *returnSize = 0;
    int *result = malloc((sLen - pLen + 1) * sizeof(int));
    for (int i = 0; i <= sLen - pLen; ++i) {
        if (isAnna(s + i, p)) {
            result[(*returnSize)++] = i;
        }
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2 ...\n");
        exit(-1);
    }

    int returnSize;
    int *result = findAnagrams(argv[1], argv[2], &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    return 0;
}