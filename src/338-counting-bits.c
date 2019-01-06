#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *result = malloc((num + 1) * sizeof(int));
    /*
    for (int i = 0; i <= num; i++) {
        result[i] = countOne(i);
    }
    */
    result[0] = 0;
    for (int i = 1; i <= num; i++) {
        result[i] = result[i & (i - 1)] + 1;
    }
    *returnSize = num + 1;
    return result;
}

// not recommended by leetcode.
int countOne(int num) {
    int result = 0;
    while (num != 0) {
        result += num % 2;
        num /= 2;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    int returnSize;
    int *result = countBits(atoi(argv[1]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
