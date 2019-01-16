#include <stdio.h>
#include <stdlib.h>

#define MIN(a,b)  ((a<b)?(a):(b))

int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes) {
    int *topMax = malloc(gridColSizes[0] * sizeof(int));
    int *leftMax = malloc(gridRowSize * sizeof(int));
    for (int i = 0; i < gridRowSize; ++i) {
        leftMax[i] = grid[i][0];
        for (int j = 1; j < gridColSizes[0]; ++j) {
            leftMax[i] = leftMax[i] > grid[i][j] ? leftMax[i] : grid[i][j];
        }
    }
    for (int i = 0; i < gridColSizes[0]; ++i) {
        topMax[i] = grid[0][i];
        for (int j = 1; j < gridRowSize; ++j) {
            topMax[i] = topMax[i] > grid[j][i] ? topMax[i] : grid[j][i];
        }
    }
    int result = 0;
    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridColSizes[0]; ++j) {
            result += MIN(leftMax[i], topMax[j]) - grid[i][j];
        }
    }
    free(topMax);
    free(leftMax);
    return result;
}


int main() {
    int **grid = malloc(4 * sizeof(int*));
    int a[] = {3, 0, 8, 4};
    int b[] = {2, 4, 5, 7};
    int c[] = {9, 2, 6, 3};
    int d[] = {0, 3, 1, 0};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    grid[3] = d;
    int gridColSizes[] = {4, 4, 4, 4};
    printf("%d", maxIncreaseKeepingSkyline(grid, 4, gridColSizes));
    free(grid);
    return 0;
}
