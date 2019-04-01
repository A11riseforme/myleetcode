#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void dfs(int A[][4], int row, int col, int r, int c) {
    A[r][c] = 0;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nr >= row || nc < 0 || nc >= col) {
            continue;
        }
        if (A[nr][nc] == 1) {
            dfs(A, row, col, nr, nc);
        }
    }
    return;
}

int numEnclaves(int A[][4], int ARowSize, int AColSize) {
    for (int i = 0; i < AColSize; ++i) {
        if (A[0][i] == 1) {
            dfs(A, ARowSize, AColSize, 0, i);
        }
        if (A[ARowSize - 1][i] == 1) {
            dfs(A, ARowSize, AColSize, ARowSize - 1, i);
        }
    }
    for (int i = 1; i < AColSize - 1; ++i) {
        if (A[i][0] == 1) {
            dfs(A, ARowSize, AColSize, i, 0);
        }
        if (A[i][AColSize - 1] == 1) {
            dfs(A, ARowSize, AColSize, i, AColSize - 1);
        }
    }
    int result = 0;
    for (int i = 1; i < ARowSize - 1; ++i) {
        for (int j = 1; j < AColSize - 1; ++j) {
            if (A[i][j] == 1) {
                ++result;
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int A[4][4] = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    printf("%d\n", numEnclaves(A, 4, 4));
    return 0;
}
