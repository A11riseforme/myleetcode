#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)

int count(int** grid, int r, int c, int i, int j) {
    int result = 0;
    if (i > 0) {
        result += MIN(grid[i][j], grid[i - 1][j]);
    }
    if (i < r - 1) {
        result += MIN(grid[i][j], grid[i + 1][j]);
    }
    if (j > 0) {
        result += MIN(grid[i][j], grid[i][j - 1]);
    }
    if (j < c - 1) {
        result += MIN(grid[i][j], grid[i][j + 1]);
    }
    return result;
}

int surfaceArea(int** grid, int gridRowSize, int *gridColSizes) {
    int n = 0;
    int common = 0;
    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridColSizes[0]; ++j) {
            if (grid[i][j] > 0) {
                n += grid[i][j];
                common += (grid[i][j] - 1) * 2;
                common += count(grid, gridRowSize, gridColSizes[0], i, j);
            }
        }
    }
    //printf("n = %d, common = %d", n, common);
    return n * 6 - common;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    */
    int **grid = malloc(3 * sizeof(int*));
    int a[] = {2, 2, 2};
    int b[] = {2, 1, 2};
    int c[] = {2, 2, 2};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    int gridColSizes[] = {3, 3, 3};
    printf("%d", surfaceArea(grid, 3, gridColSizes));
    free(grid);
    return 0;
}
