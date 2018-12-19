#include <stdio.h>
#include <stdbool.h>

void solve(char** board, int boardRowSize, int boardColSize) {
    // paint all 'O' NOT surrounded by 'X' to '*'
    for (int i = 0; i < boardRowSize; i++) {
        if (board[i][0] == 'O') {
            paint(board, boardRowSize, boardColSize, i, 0, '*');
        }
        if (board[i][boardColSize - 1] == 'O') {
            paint(board, boardRowSize, boardColSize, i, boardColSize - 1, '*');
        }
    }
    for (int i = 1; i < boardColSize - 1; i++) {
        if (board[0][i] == 'O') {
            paint(board, boardRowSize, boardColSize, 0, i, '*');
        }
        if (board[boardRowSize-1][i] == 'O') {
            paint(board, boardRowSize, boardColSize, boardRowSize-1, i, '*');
        }
    }
    // what is left is the 'O' surrounded by 'X', paint to 'X'
    for (int i = 1; i < boardRowSize - 1; i++) {
        for (int j = 1; j < boardColSize - 1; j++) {
            if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
    // paint '*' back to 'O'
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == '*') {
                board[i][j] = 'O';
            }
        }
    }
}


void paint(char **board, int boardRowSize, int boardColSize, int i, int j, char target) {
    board[i][j] = target;
    if (i > 0 && board[i-1][j] == 'O') {
        paint(board, boardRowSize, boardColSize, i-1, j, target);
    }
    if (i < boardRowSize - 1 && board[i+1][j] == 'O') {
        paint(board, boardRowSize, boardColSize, i+1, j, target);
    }
    if (j > 0 && board[i][j-1] == 'O') {
        paint(board, boardRowSize, boardColSize, i, j-1, target);
    }
    if (j < boardColSize -1 && board[i][j+1] == 'O') {
        paint(board, boardRowSize, boardColSize, i, j+1, target);
    }
    return;
}

int main(void)
{
    int i, j;
    int row_size = 5;
    int col_size = 5;
    char **board = malloc(row_size * sizeof(char *));
    board[0] = malloc(col_size);
    board[0][0] = 'X';
    board[0][1] = 'X';
    board[0][2] = 'X';
    board[0][3] = 'X';
    board[0][4] = 'X';
    board[1] = malloc(col_size);
    board[1][0] = 'O';
    board[1][1] = 'X';
    board[1][2] = 'O';
    board[1][3] = 'O';
    board[1][4] = 'X';
    board[2] = malloc(col_size);
    board[2][0] = 'O';
    board[2][1] = 'O';
    board[2][2] = 'X';
    board[2][3] = 'O';
    board[2][4] = 'X';
    board[3] = malloc(col_size);
    board[3][0] = 'X';
    board[3][1] = 'X';
    board[3][2] = 'O';
    board[3][3] = 'X';
    board[3][4] = 'X';
    board[4] = malloc(col_size);
    board[4][0] = 'X';
    board[4][1] = 'X';
    board[4][2] = 'O';
    board[4][3] = 'O';
    board[4][4] = 'X';

    for (i = 0; i < row_size; i++) {
        for (j = 0; j < col_size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    solve(board, row_size, col_size);
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < col_size; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < row_size; i++) {
        free(*(board + i));
    }
    free(board);
}
