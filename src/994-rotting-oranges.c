#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

void dfs(int** grid, int** gridcp, int gridRowSize, int gridColSize, bool* spread) {
    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridColSize; ++j) {
            if (grid[i][j] == 2) {
                if (i > 0 && grid[i - 1][j] == 1) {
                    *spread = true;
                    gridcp[i - 1][j] = 2;
                }
                if (i < gridRowSize - 1 && grid[i + 1][j] == 1) {
                    *spread = true;
                    gridcp[i + 1][j] = 2;
                }
                if (j > 0 && grid[i][j - 1] == 1) {
                    *spread = true;
                    gridcp[i][j - 1] = 2;
                }
                if (j < gridColSize - 1 && grid[i][j + 1] == 1) {
                    *spread = true;
                    gridcp[i][j + 1] = 2;
                }
            }
        }
    }
}

int orangesRotting(int** grid, int gridRowSize, int *gridColSizes) {
    bool spread = true;
    int **gridcp = malloc(gridRowSize * sizeof(int*));
    for (int i = 0; i < gridRowSize; ++i) {
        gridcp[i] = malloc(gridColSizes[0] * sizeof(int));
        memcpy(gridcp[i], grid[i], gridColSizes[0]*sizeof(int));
    }
    int result = -1;
    while (spread) {
        ++result;
        spread = false;
        dfs(grid, gridcp, gridRowSize, gridColSizes[0], &spread);
        for (int i = 0; i < gridRowSize; ++i) {
            memcpy(grid[i], gridcp[i], gridColSizes[0]*sizeof(int));
        }
    }
    for (int i = 0; i < gridRowSize; ++i) {
        for (int j = 0; j < gridColSizes[0]; ++j) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string of parentheses\n");
        exit(-1);
    }
    */
    int tmp[3][3] = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int** grid = malloc(sizeof(tmp) / sizeof(tmp[0]) * sizeof(int*));
    for (int i = 0; i < sizeof(tmp) / sizeof(tmp[0]); ++i) {
        grid[i] = malloc(sizeof(tmp[i]));
        memcpy(grid[i], tmp[i], sizeof(tmp[i]));
    }
    int gridColSizes[] = {3, 3, 3};
    printf("%d ", orangesRotting(grid, 3, gridColSizes));
    for (int i = 0; i < sizeof(tmp) / sizeof(tmp[0]); ++i) {
        free(grid[i]);
    }
    free(grid);
}
