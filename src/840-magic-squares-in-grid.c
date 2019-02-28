#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int numMagicSquaresInside(int** grid, int gridRowSize, int *gridColSizes) {
    if (gridRowSize < 3 || gridColSizes[0] < 3) {
        return 0;
    }
    int curr;
    int horizontal[3];
    int vertical[3];
    int result = 0;
    bool valid;
    for (int i = 0; i < gridRowSize - 2; ++i) {
        for (int j = 0; j < gridColSizes[0] - 2; ++j) {
            curr = 0;
            valid = true;
            memset(horizontal, 0, sizeof(horizontal));
            memset(vertical, 0, sizeof(vertical));
            for (int r = 0; r < 3; ++r) {
                for (int c = 0; c < 3; ++c) {
                    horizontal[r] += grid[r + i][c + j];
                    vertical[c] += grid[r + i][c + j];
                    curr |= 1 << grid[r + i][c + j];
                }
            }
            for (int k = 0; k < 3; ++k) {
                if (horizontal[k] != 15 || vertical[k] != 15) {
                    valid = false;
                    break;
                }
            }
            if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != 15 ||
                    grid[i + 2][j] + grid[i + 1][j + 1] + grid[i][j + 2] != 15) {
                valid = false;
            }
            if (valid && curr == 1022) {
                ++result;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }
    */
    int **grid = malloc(3 * sizeof(int*));
    for (int i = 0; i < 3; ++i) {
        grid[i] = malloc(4 * sizeof(int));
    }
    int a[] = {4, 3, 8, 4};
    int b[] = {9, 5, 1, 9};
    int c[] = {2, 7, 6, 2};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    int gridColSizes[3] = {4, 4, 4};

    printf("%d\n", numMagicSquaresInside(grid, 3, gridColSizes));

    for (int i = 0; i < 3; ++i) {
        free(grid[i]);
    }
    free(grid);
    return 0;
}
