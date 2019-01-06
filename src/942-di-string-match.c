#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int len = strlen(S);
    *returnSize = len + 1;
    int *result = malloc((len + 1) * sizeof(int));
    int max = len;
    int min = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] == 'I') {
            result[i] = min++;
            continue;
        }
        result[i] = max--;
    }
    result[len] = max;
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    int returnSize;
    int *result = diStringMatch(argv[1], &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
}
