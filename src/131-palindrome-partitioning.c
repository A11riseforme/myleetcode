#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* s, int start, int end) {
    while(end >= start) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
  }
  return true;
}


void helper(char* s, int length, char*** result, int** columnSizes, int* returnSize, char** tmp, int size, int start) {
    if (*(s + start) == '\0') {
        result[*returnSize] = calloc(size, sizeof(char*));
        for (int i = 0; i < size; i++) {
            result[*returnSize][i] = calloc(strlen(tmp[i])+1, sizeof(char));
            strcpy(result[*returnSize][i], tmp[i]);
        }
        (*columnSizes)[(*returnSize)++] = size;
        return;
    }
    for (int i = start; i < length; i++) {
        if (isPalindrome(s, start, i)) {
            memcpy(tmp[size], s + start, i - start + 1);
            tmp[size][i - start +1] = '\0';
            helper(s, length, result, columnSizes, returnSize, tmp, size + 1, i + 1);
        }
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** partition(char* s, int** columnSizes, int* returnSize) {
    int len = strlen(s);
    if (len == 0) {
        *returnSize = 0;
        return NULL;
    }
    char ***result = calloc(512, sizeof(char **));
    *columnSizes = calloc(512, sizeof(int));
    char **tmp = calloc(512, sizeof(char *));
    for (int i = 0; i < 512; i++) {
        *(tmp + i) = calloc(len+1, sizeof(char));
    }
    *returnSize = 0;
    helper(s, len, result, columnSizes, returnSize, tmp, 0, 0);
    for (int i = 0; i < 512; i++) {
        free(*(tmp + i));
    }
    free(tmp);
    return result;
}


// memory leak is inevitable up to my ability right now.
int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }

    int i, j, count = 0;
    int *col_sizes;
    char ***lists = partition(argv[1], &col_sizes, &count);
    for (i = 0; i < count; i++) {
        char **list = lists[i];
        for (j = 0; j < col_sizes[i]; j++) {
            printf("%s ", list[j]);
        }
        printf("\n");
    }
    return 0;
}
