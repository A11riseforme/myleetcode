#include <stdio.h>
#include <stdlib.h>

int calc(int** grid, int r, int c, int i, int j) {
    if (grid[i][j] == 0) {
        return 0;
    }
    int result = 0;
    if (j == 0 || grid[i][j - 1] == 0) {
        result++;
    }
    if (j == c - 1 || grid[i][j + 1] == 0) {
        result++;
    }
    if (i == 0 || grid[i - 1][j] == 0) {
        result++;
    }
    if (i == r - 1 || grid[i + 1][j] == 0) {
        result++;
    }
    return result;
}

// very intuitive method.
int islandPerimeter(int** grid, int gridRowSize, int gridColSize) {
    int result = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize; j++) {
            result += calc(grid, gridRowSize, gridColSize, i, j);
        }
    }
    return result;
}

// smarter method. every island will initially contribute 4
// to the perimeter, and every connected pairs will reduce
// the perimeter by 2.
int islandPerimeterSmart(int** grid, int gridRowSize, int gridColSize) {
    int num = 0;
    int connectNum = 0;
    for (int i = 0; i < gridRowSize; i++) {
        for (int j = 0; j < gridColSize - 1; j++) {
            if (grid[i][j] == 1) {
                num++;
                if (grid[i][j] == grid[i][j + 1]) {
                    connectNum++;
                }
            }
        }
        if (grid[i][gridColSize - 1] == 1) {
            num++;
        }
    }
    for (int i = 0; i < gridColSize; i++) {
        for (int j = 0; j < gridRowSize - 1; j++) {
            if (grid[j][i]*grid[j + 1][i] == 1) {
                connectNum++;
            }
        }
    }
    return num * 4 - 2 * connectNum;
}

int main() {
    int **grid = malloc(4 * sizeof(int*));
    int a[] = {0, 1, 0, 0};
    int b[] = {1, 1, 1, 0};
    int c[] = {0, 1, 0, 0};
    int d[] = {1, 1, 0, 0};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    grid[3] = d;
    printf("%d", islandPerimeter(grid, 4, 4));
    free(grid);
    return 0;
}
