#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canSelfDivide(int n) {
    int m = n;
    int last;
    while (m > 0) {
        last = m % 10;
        if (last == 0 || n % last != 0) {
            return false;
        }
        m /= 10;
    }
    return true;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int *result = malloc((right - left + 1) * sizeof(int));
    int count = 0;
    for (int i = left; i <= right; ++i) {
        if (canSelfDivide(i)) {
            result[count++] = i;
        }
    }
    *returnSize = count;
    return result;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test left right\n");
        exit(-1);
    }
    int returnSize;
    int *result = selfDividingNumbers(atoi(argv[1]), atoi(argv[2]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
