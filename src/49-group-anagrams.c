#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hashTable {
    char *word;
    int num;
    int indexes[10];
};


static int cmp(const void *a, const void *b) {
    return *(char *) a - *(char *) b;
}


int BKDRHash(char *s, int size) {
    int seed = 31;
    unsigned long hash = 0;
    while (*s != '\0') {
        hash = hash * seed + *s++;
    }
    return hash % size;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {
    struct hashTable *ht = calloc(strsSize, sizeof(*ht));
    char **currentStr = calloc(strsSize, sizeof(char *));
    int rowSize = 0;
    int j = 0;
    int k = 0;
    for (int i = 0; i < strsSize; i++) {
        int currentStrLength = strlen(strs[i]);
        currentStr[i] = calloc(currentStrLength + 1, sizeof(char));
        memcpy(currentStr[i], strs[i], currentStrLength + 1);
        qsort(currentStr[i], currentStrLength, sizeof(char), cmp);
        int hash = BKDRHash(currentStr[i], strsSize);
        j = hash;
        // if num > 0 and ht[j].word != currentStr[i], not the same string, avoid hash collision.
        while (ht[j].num > 0 && strcmp(ht[j].word, currentStr[i])) {
            j = ++j % strsSize;
        }
        if (ht[j].num == 0) {
            ht[j].word = currentStr[i];
            rowSize++;
        }
        ht[j].indexes[ht[j].num++] = i;
    }

    for (int i = 0; i < strsSize; i++) {
        free(*(currentStr + i));
    }
    free(currentStr);

    char ***lists = calloc(rowSize, sizeof(char **));
    *columnSizes = calloc(rowSize, sizeof(int));
    for (int i = 0; i < strsSize; i++) {
        if (ht[i].num > 0) {
            (*columnSizes)[k] = ht[i].num;
            lists[k] = calloc(ht[i].num, sizeof(char *));
            for (int j = 0; j < ht[i].num; j++) {
                int index = ht[i].indexes[j];
                lists[k][j] = strs[index];
            }
            k++;
        }
    }
    free(ht);
    *returnSize = rowSize;
    return lists;
}


int main() {
    char **strs = calloc(6, sizeof(char *));
    *(strs + 0) = "eat";
    *(strs + 1) = "tea";
    *(strs + 2) = "tan";
    *(strs + 3) = "ate";
    *(strs + 4) = "nat";
    *(strs + 5) = "bat";
    int *columnSizes, returnSize = 0;
    char ***lists = groupAnagrams(strs, 6, &columnSizes, &returnSize);
    printf("returnSize = %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < columnSizes[i]; j++) {
            printf("%s ", lists[i][j]);
        }
        printf("\n");
    }
    free(columnSizes);
    free(strs);
    for (int i = 0; i < returnSize; i++) {
        free(*(lists + i));
    }
    free(lists);
}

