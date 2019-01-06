#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * by observation:
 * i    bin    '1's  i&(i-1)
 * 0    0000    0
 * -----------------------
 * 1    0001    1    0000
 * -----------------------
 * 2    0010    1    0000
 * 3    0011    2    0010
 * -----------------------
 * 4    0100    1    0000
 * 5    0101    2    0100
 * 6    0110    2    0100
 * 7    0111    3    0110
 * -----------------------
 * 8    1000    1    0000
 * 9    1001    2    1000
 * 10   1010    2    1000
 * 11   1011    3    1010
 * 12   1100    2    1000
 * 13   1101    3    1100
 * 14   1110    3    1100
 * 15   1111    4    1110
 * hence: result[i] = result[i & (i - 1)] + 1
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
