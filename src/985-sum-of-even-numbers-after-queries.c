#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sumEvenAfterQueries(int* A, int ASize, int** queries, int queriesRowSize, int* returnSize) {
    int evenSum = 0;
    for (int i = 0; i < ASize; ++i) {
        if (A[i] & 1) {
            continue;
        }
        evenSum += A[i];
    }
    *returnSize = 0;
    int *result = malloc(queriesRowSize * sizeof(int));
    for (int i = 0; i < queriesRowSize; ++i) {
        // original number is odd
        if (A[queries[i][1]] & 1) {
            // addition is odd
            if (queries[i][0] & 1) {
                A[queries[i][1]] += queries[i][0];
                evenSum += A[queries[i][1]];
                // addition is even
            } else {
                A[queries[i][1]] += queries[i][0];

            }
            // original number is even
        } else {
            // addition is odd
            if (queries[i][0] & 1) {
                evenSum -= A[queries[i][1]];
                A[queries[i][1]] += queries[i][0];
                // addition is even
            } else {
                evenSum += queries[i][0];
                A[queries[i][1]] += queries[i][0];
            }
        }
        result[(*returnSize)++] = evenSum;
    }
    return result;
}


int main(int argc, char** argv) {
    int A[] = {1, 2, 3, 4};
    int **query = malloc(4 * sizeof(int*));
    int a[] = {1, 0};
    int b[] = {-3, 1};
    int c[] = {-4, 0};
    int d[] = {2, 3};
    query[0] = a;
    query[1] = b;
    query[2] = c;
    query[3] = d;
    int returnSize;
    int *result = sumEvenAfterQueries(A, sizeof(A) / sizeof(A[0]), query, 4, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }
    free(result);
    free(query);
    return 0;
}
