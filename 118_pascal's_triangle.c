#include <stdio.h>
#include <stdlib.h>
/**
 * Return an array of arrays.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes) {
    int **triangle = calloc(numRows, sizeof(int *));
    *columnSizes = calloc(numRows, sizeof(int *));
    for (int i = 0; i < numRows; i += 1) {
        int num = i + 1;
        (*columnSizes)[i] = num;
        triangle[i] = calloc(num, sizeof(int));
        triangle[i][0] = 1;
        triangle[i][num - 1] = 1;
        for (int j = 1; j <= num - 2; j += 1) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }
    int i, j, *sizes, row = atoi(argv[1]);
    int **triangle = generate(row, &sizes);
    for (i = 0; i < row; i++) {
        for (int j = 0; j < row - i - 1; j++) {
            printf(" ");
        }
        for (j = 0; j < sizes[i]; j++) {
            printf("%2d ", triangle[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row; i++) {
        free(*(triangle + i));
    }
    free(triangle);
    return 0;
}
