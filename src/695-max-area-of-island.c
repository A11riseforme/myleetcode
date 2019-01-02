#include <stdio.h>
#include <stdlib.h>

int dfs(int** grid, int gridRowSize, int gridColSize, int i, int j, int area) {
    grid[i][j] = 0;
    if (i > 0 && grid[i - 1][j] == 1) {
        area += dfs(grid, gridRowSize, gridColSize, i - 1, j, 1);
    }
    if (j > 0 && grid[i][j - 1] == 1) {
        area += dfs(grid, gridRowSize, gridColSize, i, j - 1, 1);
    }
    if (i < gridRowSize - 1 && grid[i + 1][j] == 1) {
        area += dfs(grid, gridRowSize, gridColSize, i + 1, j, 1);
    }
    if (j < gridColSize - 1 && grid[i][j + 1] == 1) {
        area += dfs(grid, gridRowSize, gridColSize, i, j + 1, 1);
    }
    return area;
}


int maxAreaOfIsland(int** grid, int gridRowSize, int gridColSize) {
    int result = 0;
    int currArea;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            if (grid[i][j] == 1) {
                currArea = dfs(grid, gridRowSize, gridColSize, i, j, 1);
                result = currArea > result ? currArea : result;
            }
        }
    }
    return result;
}

int main() {
    int **grid = malloc(4 * sizeof(int*));
    int a[] = {1, 1, 0, 0, 0};
    int b[] = {1, 1, 0, 0, 0};
    int c[] = {0, 0, 0, 1, 1};
    int d[] = {0, 0, 0, 1, 1};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    grid[3] = d;
    printf("%d", maxAreaOfIsland(grid, 4, 5));
    free(grid);
}
