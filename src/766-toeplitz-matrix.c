#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isToeplitzMatrix(int **matrix, int matrixRowSize, int *matrixColSizes) {
    int r, c;
    for (int i = matrixRowSize - 1; i >= 0; --i) {
        c = 0;
        r = i;
        while (r >= 0 && r < matrixRowSize - 1 && c >= 0 &&
               c < matrixColSizes[0] - 1) {
            if (matrix[r][c] != matrix[r + 1][c + 1]) {
                return false;
            }
            ++r;
            ++c;
        }
    }
    for (int j = 1; j < matrixColSizes[0]; ++j) {
        r = 0;
        c = j;
        while (r >= 0 && r < matrixRowSize - 1 && c >= 0 &&
               c < matrixColSizes[0] - 1) {
            if (matrix[r][c] != matrix[r + 1][c + 1]) {
                return false;
            }
            ++r;
            ++c;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int **matrix = malloc(3 * sizeof(int *));
    int row1[4] = {1, 2, 3, 4};
    int row2[4] = {5, 1, 2, 3};
    int row3[4] = {9, 5, 1, 2};
    matrix[0] = row1;
    matrix[1] = row2;
    matrix[2] = row3;
    int matrixColSizes[3] = {4, 4, 4};
    printf("%s\n", isToeplitzMatrix(matrix, 3, matrixColSizes) ? "yes" : "no");
    return 0;
}