#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// using extra space
void gameOfLife(int** board, int boardRowSize, int *boardColSizes) {
    int dir[8][2] = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int** dup = malloc(boardRowSize * sizeof(int*));
    for (int i = 0; i < boardRowSize; ++i) {
        dup[i] = malloc(boardColSizes[i] * sizeof(int));
        memcpy(dup[i], board[i], boardColSizes[i]*sizeof(int));
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSizes[i]; ++j) {
            int cnt = 0;
            for (int k = 0; k < 8; ++k) {
                int nr = i + dir[k][0];
                int nc = j + dir[k][1];
                if (nr < 0 || nr >= boardRowSize || nc < 0 || nc >= boardColSizes[i]) {
                    continue;
                }
                cnt += (dup[nr][nc] == 1);
            }
            if (dup[i][j] == 0) {
                if (cnt == 3) {
                    board[i][j] = 1;
                }
            } else {
                if (cnt < 2 || cnt > 3) {
                    board[i][j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < boardRowSize; ++i) {
        free(dup[i]);
    }
    free(dup);
}


// bit manipulation
void gameOfLifeBit(int** board, int boardRowSize, int *boardColSizes) {
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSizes[i]; ++j) {
            int cnt = 0;
            for (int r = -1; r <= 1; ++r) {
                for (int c = -1; c <= 1; ++c) {
                    int nr = i + r;
                    int nc = j + c;
                    if (nr < 0 || nr >= boardRowSize || nc < 0 || nc >= boardColSizes[i]) {
                        continue;
                    }
                    cnt += board[nr][nc]&1;
                }
            }
            if (cnt == 3 || cnt - (board[i][j]&1) == 3) {
                board[i][j] |= 2;
            }
        }
    }
    for (int i = 0; i < boardRowSize; ++i) {
        for (int j = 0; j < boardColSizes[i]; ++j) {
            board[i][j] >>= 1;
        }
    }
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int **board = malloc(4 * sizeof(int*));
    int nums1[] = {0, 1, 0};
    int nums2[] = {0, 0, 1};
    int nums3[] = {1, 1, 1};
    int nums4[] = {0, 0, 0};
    board[0] = nums1;
    board[1] = nums2;
    board[2] = nums3;
    board[3] = nums4;
    int boardColSizes[] = {3, 3, 3, 3};
    gameOfLife(board, 4, boardColSizes);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    return 0;
}

