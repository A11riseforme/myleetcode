#include <stdio.h>
#include <stdlib.h>

void generateCombine(int n, int k, int pos, int index, int *initial, int *tmpResult, int **result, int *count) {
    if (index == k) {
        for (int i = 0; i < k; i++) {
            *(*(result + *count) + i) = tmpResult[i];
        }
        (*count)++;
        return;
    }
    for (int i = pos; i < n; i++) {
        tmpResult[index] = initial[i];
        generateCombine(n, k, i + 1, index + 1, initial, tmpResult, result, count);
    }
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int** columnSizes, int* returnSize) {
    *returnSize = 1;
    // just to prevent overflow when calculating nCk.
    int a = k < n / 2 ? k : n - k;
    for (int i = n; i > n - a; i--) {
        *returnSize *= i;
    }
    for (int i = 1; i <= a; i++) {
        *returnSize /= i;
    }
    int **result = calloc(*returnSize, sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = calloc(k, sizeof(int));
    }
    *columnSizes = calloc(*returnSize, sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        *(*columnSizes + i) = k;
    }
    int initial[n];
    for (int i = 0; i < n; i++) {
        initial[i] = i + 1;
    }
    int tmpResult[k];
    int count = 0;
    generateCombine(n, k, 0, 0, initial, tmpResult, result, &count);
    return result;
}

int main() {
    int n = 5;
    int k = 3;
    int *columnSizes;
    int returnSize;
    int **result = combine(n, k, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < * (columnSizes + i); j++) {
            printf("%d ", *(*(result + i) + j));
        }
        printf("\n");
    }
    for (int i = 0; i < returnSize; i++) {
        free(*(result + i));
    }
    free(result);
    free(columnSizes);
}
