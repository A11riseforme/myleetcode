#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    char a;
    int start;
    int end;
} range;

int* partitionLabels(char* s, int* returnSize) {
    bool *found = malloc(26 * sizeof(bool));
    memset(found, false, 26);
    range *ranges = malloc(26 * sizeof(range));
    for (int i = 0; s[i] != '\0'; ++i) {
        if (!found[s[i] - 'a']) {
            found[s[i] - 'a'] = true;
            ranges[s[i] - 'a'].start = i;
            ranges[s[i] - 'a'].end = i;
        } else {
            ranges[s[i] - 'a'].end = i;
        }
    }
    int left = 0;
    *returnSize = 0;
    bool flag  = true;
    int *result = malloc(500 * sizeof(int));
    for (int i = 0; s[i] != '\0'; ++i) {
        if (ranges[s[i] - 'a'].end <= i) {
            for (int j = 0; j < 26; ++j) {
                if (found[j] && ranges[j].start < i && ranges[j].end > i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result[(*returnSize)++] = i - left + 1;
                left = i + 1;
            }
            flag = true;
        }
    }
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    int returnSize;
    int *result = partitionLabels(argv[1], &returnSize);
    printf("%d\n", returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
