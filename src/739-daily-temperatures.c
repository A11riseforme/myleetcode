#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize) {
    int *result = malloc(TSize * sizeof(int));
    for (int i = TSize - 1; i >= 0; --i) {
        int j = i + 1;
        while (j < TSize && T[j] <= T[i]) {
            // skip useless temp.
            if (result[j] > 0) {
                j = result[j] + j;
            }
            // if from T[j] onwards, no higher temp than T[j]
            // since T[j] <= T[i], no higher temp than T[i]
            else {
                j = TSize;
            }
        }
        // j is still within the TSize, found the next higher tmp
        if (j < TSize) {
            result[i] = j - i;
            // haven't found the next higher tmp, result[i] = 0;
        } else {
            result[i] = 0;
        }
    }
    *returnSize = TSize;
    return result;
}

int main() {
    int temperature[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int returnSize;
    int *result = dailyTemperatures(temperature, sizeof(temperature) / sizeof(temperature[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
}
