#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* prisonAfterNDays(int* cells, int cellsSize, int N, int* returnSize) {
    N = (N - 1) % 14 + 1; // period is always 14 after several checks.
    for (int i = 0; i < N; i++) {
        int *ref = calloc(cellsSize, sizeof(int));
        for (int j = 1; j < cellsSize - 1; j++) {
            ref[j] = 1 - (cells[j - 1] ^ cells[j + 1]);
        }
        memcpy(cells, ref, sizeof(int)*cellsSize);
        free(ref);
    }
    *returnSize = cellsSize;
    return cells;
}

int main() {
    int nums[] = {0, 1, 0, 1, 1, 0, 0, 1};
    int returnSize;
    int *result = prisonAfterNDays(nums, 8, 7, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    free(result);
    return 0;
}
