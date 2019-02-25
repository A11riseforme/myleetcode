#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


int numRookCaptures(char (*board)[8]) {
    int dir[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int x, y;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i][j] == 'R') {
                y = i;
                x = j;
            }
        }
    }
    int r, c;
    int result = 0;
    for (int d = 0; d < 4; ++d) {
        r = y;
        c = x;
        while(true) {
            r += dir[d][0];
            c += dir[d][1];
            if (r >= 8 || r < 0 || c >= 8 || c < 0) {
                break;
            }
            if (board[r][c] == 'p') {
                ++result;
                break;
            }
            if (board[r][c] == 'B') {
                break;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */
    char board[8][8] = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'p', 'p', '.', 'R', '.', 'p', 'B', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'p', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'}
    };
    printf("%d\n", numRookCaptures(board));
    return 0;
}
