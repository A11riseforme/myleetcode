#include <stdio.h>
#include <stdlib.h>

// update grid IN PLACE, space complexity is O(1)
int minPathSum(int **grid, int gridRowSize, int gridColSize) {
    for (int i = 1; i < gridColSize; i++) {
        grid[0][i] += grid[0][i-1];
    }
    for (int i = 1; i < gridRowSize; i++) {
        grid[i][0] += grid[i-1][0];
    }
    for (int i = 1; i < gridRowSize; i++) {
        for (int j = 1; j < gridColSize; j++) {
            grid[i][j] += grid[i][j-1] > grid[i-1][j] ? grid[i-1][j] : grid[i][j-1];
        }
    }
    return grid[gridRowSize - 1][gridColSize - 1];
}


int main() {
    int **grid = calloc(3, sizeof(int *));
    int a[3] = {1,3,1};
    int b[3] = {1,5,1};
    int c[3] = {4,2,1};
    *(grid + 0) = a;
    *(grid + 1) = b;
    *(grid + 2) = c;
    printf("minimum path sum is %d",minPathSum(grid, 3, 3));
    free(grid);
}
