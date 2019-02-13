#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

int expand(int** grid, int n, int i, int j, int r) {
    if (i - r < 0 || i + r >= n || j - r < 0 || j + r >= n) {
        return 0;
    }
    if (grid[i - r][j] == 1 || grid[i + r][j] == 1 || grid[i][j - r] == 1 || grid[i][j + r] == 1) {
        return 0;
    }
    return 1 + expand(grid, n, i, j, r + 1);
}

// slow, will update using dp.
int orderOfLargestPlusSign(int N, int (*mines)[2], int minesRowSize) {
    int **grid = calloc(N, sizeof(int*));
    for (int i = 0; i < N; ++i) {
        grid[i] = calloc(N, sizeof(int));
    }
    for (int i = 0; i < minesRowSize; ++i) {
        grid[mines[i][0]][mines[i][1]] = 1;
    }
    int result = 0;
    int curr;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!grid[i][j]) {
                curr = 1 + expand(grid, N, i, j, 1);
                result = MAX(curr, result);
            }
        }
    }
    return result;
}

// dp solution
int orderOfLargestPlusSignDP(int N, int (*mines)[2], int minesRowSize) {
    int **grid = calloc(N, sizeof(int*));
    for (int i = 0; i < N; ++i) {
        grid[i] = calloc(N, sizeof(int));
    }
    for (int i = 0; i < minesRowSize; ++i) {
        grid[mines[i][0]][mines[i][1]] = 1;
    }
    int **fromleft = malloc(N * sizeof(int*));
    int **fromright = malloc(N * sizeof(int*));
    int **fromtop = malloc(N * sizeof(int*));
    int **frombottom = malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        fromleft[i] = malloc(N * sizeof(int));
        fromleft[i][0] = 1 - grid[i][0];
        for (int j = 1; j < N; ++j) {
            if (grid[i][j] == 1) {
                fromleft[i][j] = 0;
            } else {
                fromleft[i][j] = 1 + fromleft[i][j - 1];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        fromright[i] = malloc(N * sizeof(int));
        fromright[i][N - 1] = 1 - grid[i][N - 1];
        for (int j = N - 2; j >= 0; --j) {
            if (grid[i][j] == 1) {
                fromright[i][j] = 0;
            } else {
                fromright[i][j] = 1 + fromright[i][j + 1];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        // fromtop[i][j] is the longest consecutive 1s from top, at jth row, ith column
        fromtop[i] = malloc(N * sizeof(int));
        fromtop[i][0] = 1 - grid[0][i];
        for (int j = 1; j < N; ++j) {
            if (grid[j][i] == 1) {
                fromtop[i][j] = 0;
            } else {
                fromtop[i][j] = 1 + fromtop[i][j - 1];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        // frombottom[i][j] is the longest consecutive 1s from bottom, at jth row, ith column
        frombottom[i] = malloc(N * sizeof(int));
        frombottom[i][N - 1] = 1 - grid[N - 1][i];
        for (int j = N - 2; j >= 0; --j) {
            if (grid[j][i] == 1) {
                frombottom[i][j] = 0;
            } else {
                frombottom[i][j] = 1 + frombottom[i][j + 1];
            }
        }
    }
    int result = 0, curr;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            curr = MIN(MIN(fromleft[i][j], fromright[i][j]), MIN(fromtop[j][i], frombottom[j][i]));
            result = MAX(result, curr);
        }
    }
    for (int i = 0; i < N; ++i) {
        free(fromleft[i]);
        free(fromright[i]);
        free(fromtop[i]);
        free(frombottom[i]);
        free(grid[i]);
    }
    free(fromleft);
    free(fromright);
    free(fromtop);
    free(frombottom);
    free(grid);
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int mines[][2] = {{4, 2}};
    int N = 5;
    printf("%d", orderOfLargestPlusSignDP(N, mines, 1));
    return 0;
}
