#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char **result = malloc(n * sizeof(char*));
    char a[] = "Buzz";
    char b[] = "Fizz";
    char c[] = "FizzBuzz";
    for (int i = 1; i <= n; ++i) {
        if (i % 15 == 0) {
            result[i - 1] = malloc(9 * sizeof(char));
            memcpy(result[i - 1], c, 9);
        } else if (i % 3 == 0) {
            result[i - 1] = malloc(5 * sizeof(char));
            memcpy(result[i - 1], b, 5);
        } else if (i % 5 == 0) {
            result[i - 1] = malloc(5 * sizeof(char));
            memcpy(result[i - 1], a, 5);
        } else {
            result[i - 1] = malloc(12 * sizeof(char));
            sprintf(result[i - 1], "%d", i);
        }
    }
    *returnSize = n;
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    int returnSize;
    char **result = fizzBuzz(atoi(argv[1]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
