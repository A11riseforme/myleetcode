#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int** grid, int r, int c, int r0, int c0) {
    int ori = grid[r0][c0];
    grid[r0][c0] = -ori;
    for (int i = 0; i < 4; ++i) {
        int tmpr = r0+dir[i][0];
        int tmpc = c0+dir[i][1];
        if (tmpr < 0 || tmpr >= r || tmpc < 0 || tmpc >= c || grid[tmpr][tmpc] != ori) {
            continue;
        }
        dfs(grid, r, c, tmpr, tmpc);
    }
    if (r0 > 0 && r0 < r-1 && c0 > 0 && c0 < c-1 && abs(grid[r0-1][c0]) == ori && abs(grid[r0+1][c0]) == ori && abs(grid[r0][c0-1]) == ori && abs(grid[r0][c0+1]) == ori) {
        grid[r0][c0] = ori;
    }
    return;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** colorBorder(int** grid, int gridSize, int* gridColSize, int r0, int c0, int color/*, int* returnSize, int** returnColumnSizes*/){
    dfs(grid, gridSize, gridColSize[0], r0, c0);
    //*returnSize = gridSize;
    //*returnColumnSizes = malloc(gridSize*sizeof(int*));
    for (int i = 0; i < gridSize; ++i) {
        //(*returnColumnSizes)[i] = gridColSize[0];
        for (int j = 0; j < gridColSize[0]; ++j) {
            if (grid[i][j] < 0) {
                grid[i][j] = color;
            }
        }
    }
    return grid;
}

int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int **grid = malloc(3*sizeof(int*));
    int *gridColSize = malloc(3*sizeof(int));
    for (int i = 0; i < 3; ++i) {
        //grid[i] = malloc(3*sizeof(int));
        gridColSize[i] = 3;
    }
    int nums0[] = {1,2,1};
    int nums1[] = {2,2,2};
    int nums2[] = {1,2,1};
    grid[0] = nums0;
    grid[1] = nums1;
    grid[2] = nums2;
    int **result = colorBorder(grid, 3, gridColSize, 1, 1, 3);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    free(grid);
    free(gridColSize);
    return 0;
}