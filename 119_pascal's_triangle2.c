#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;
    int *result = calloc(*returnSize, sizeof(int));
    for (int i = 0; i <= rowIndex; i++) {
        *(result + i) = nChoosek(rowIndex, i);
    }
    return result;
}


int nChoosek(int n, int k) {
    long long result = 1;
    long a = k < n / 2 ? k : n - k;
    int tmp = n - a;
    int b = 1;
    while (n > tmp && b <= a) {
        result = result * n / b; // reduction as soon a possible so as to prevent overflow.
        n--;
        b++;
    }
    if (n > tmp) {
        while (n > tmp) {
            result *= n;
            n--;
        }
    }
    if (b <= a) {
        while (n <= a) {
            result /= b;
            b++;
        }
    }
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }
    int i, j, count = 0, row_idx = atoi(argv[1]);
    int *row = getRow(row_idx, &count);
    for (i = 0; i < count; i++) {
        printf("%d ", row[i]);
    }
    free(row);
    return 0;
}
