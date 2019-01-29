#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsRowSize, int *pointsColSizes, int K, int** columnSizes, int* returnSize) {
    int **result = malloc(K*sizeof(int*));
    *columnSizes = malloc(K*sizeof(int));
    bool swap;
    for (int i = 0; i < pointsRowSize-1; ++i) {
        swap = false;
        for (int j = 0; j < pointsRowSize-1-i; ++j) {
            if (points[j][0]*points[j][0]+points[j][1]*points[j][1] > 
                points[j+1][0]*points[j+1][0]+points[j+1][1]*points[j+1][1]) {
                swap = true;
                points[j][0] ^= points[j+1][0] ^= points[j][0] ^= points[j+1][0];
                points[j][1] ^= points[j+1][1] ^= points[j][1] ^= points[j+1][1];
            }
        }
        if (!swap) {
            break;
        }
    }
    
    for (int i = 0; i < K; ++i) {
        (*columnSizes)[i] = 2;
        result[i] = malloc(2*sizeof(int));
        result[i][0] = points[i][0];
        result[i][1] = points[i][1];
    }
    *returnSize = K;
    return result;
}


int main() {
    //skipped
}
