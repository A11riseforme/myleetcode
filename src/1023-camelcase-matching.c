#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool judge(char* query, char* pattern) {
    int j = 0;
    int plen = strlen(pattern);
    int qlen = strlen(query);
    for (int i = 0; i < qlen; i++) {
        if (j < plen && query[i] == pattern[j]) {
            j++;
            // return false if capital letter in query does not match
        } else if (isupper(query[i])) {
            return false;
        }
    }
    return j == plen;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    bool *result = malloc(queriesSize * sizeof(bool));
    *returnSize = queriesSize;
    for (int i = 0; i < queriesSize; ++i) {
        result[i] = judge(queries[i], pattern);
    }
    return result;
}

// ./test.exe FB FooBar FooBarTest FootBall
int main(int argc, char **argv) {

    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }

    char **queries = malloc((argc - 2) * sizeof(char*));
    for (int i = 0; i < argc - 2; ++i) {
        queries[i] = argv[i + 2];
    }
    int returnSize;
    bool *result = camelMatch(queries, argc - 2, argv[1], &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s ", result[i] ? "yes" : "no");
    }
    return 0;
}

