#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findLength(int* A, int ASize, int* B, int BSize) {
    // table[i][j] means max length of repeated subarray of A up to i and B up to j.
    int **table = malloc(ASize * sizeof(int*));
    for (int i = 0; i < ASize; i++) {
        table[i] = calloc(BSize, sizeof(int));
    }

    for (int i = 0; i < ASize; i++) {
        if (A[i] == B[0]) {
            table[i][0] = 1;
        }
    }
    for (int i = 1; i < BSize; i++) {
        if (B[i] == A[0]) {
            table[0][i] = 1;
        }
    }
    int result = table[0][0];
    for (int i = 1; i < ASize; i++) {
        for (int j = 1; j < BSize; j++) {
            if (A[i] == B[j]) {
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            result = result < table[i][j] ? table[i][j] : result;
        }
        free(table[i]);
    }
    free(table);
    return result;
}

int main() {
    int nums1[] = {1, 2, 3, 2, 1};
    int nums2[] = {3, 2, 1, 4, 7};
    printf("%d", findLength(nums1, 5, nums2, 5));
    return 0;
}
