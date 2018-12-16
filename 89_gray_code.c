#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 * PS. Honestly I don't know how this works, I just checked how graycode is generated.
 */
int* grayCode(int n, int* returnSize) {
    *returnSize = (int)pow(2, n);
    int *result = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = (i ^ (i >> 1)); // G(n) = B(n)^B(n/2)
    }
    return result;
}


int main() {
    int n = 4;
    int returnSize;
    int *result = grayCode(n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        char s[5];
        itoa(result[i], s, 2);
        printf("%2d : %04s\n", result[i], s);
    }
}
