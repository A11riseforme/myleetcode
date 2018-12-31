#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool fillup (char** board, bool** rowNums, bool** colNums, bool** boxNums, int row, int col) {
    // when row == 9, it means from 0 to 8th row has been filled up, so finished.
    if (row == 9) {
        return true;
    }

    int nextCol = (col + 1) % 9;
    int nextRow = (nextCol == 0) ? row + 1 : row;

    // if the next grid is filled up already, move on.
    if (board[row][col] != '.') {
        return fillup(board, rowNums, colNums, boxNums, nextRow, nextCol);
    }

    for (int i = 1; i < 10; i++) {
        int boxRowNum = row / 3;
        int boxColNum = col / 3;
        int boxIndex = boxRowNum * 3 + boxColNum;
        if (!rowNums[row][i] && !colNums[col][i] && !boxNums[boxIndex][i]) {
            rowNums[row][i] = true;
            colNums[col][i] = true;
            boxNums[boxIndex][i] = true;
            board[row][col] = '0' + i;
            if (fillup(board, rowNums, colNums, boxNums, nextRow, nextCol)) {
                return true;
            }
            // backtracking
            rowNums[row][i] = false;
            colNums[col][i] = false;
            boxNums[boxIndex][i] = false;
            board[row][col] = '.';

        }
    }
    return false;
}


void solveSudoku(char** board, int boardRowSize, int boardColSize) {
    // rowNums[i][n] == true means in the ith row, number n is used already. same for ColNums, boxNums
    bool **rowNums = malloc(9 * sizeof(bool*));
    for (int i = 0; i < 9; i++) {
        rowNums[i] = calloc(10, sizeof(bool));
    }
    bool **colNums = malloc(9 * sizeof(bool*));
    for (int i = 0; i < 9; i++) {
        colNums[i] = calloc(10, sizeof(bool));
    }
    bool **boxNums = malloc(9 * sizeof(bool*));
    for (int i = 0; i < 9; i++) {
        boxNums[i] = calloc(10, sizeof(bool));
    }
    // initialize rowNums, colNums, boxNums.
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c != '.') {
                int number = c - '0';
                int boxRowNum = i / 3;
                int boxColNum = j / 3;
                rowNums[i][number] = true;
                colNums[j][number] = true;
                boxNums[boxRowNum * 3 + boxColNum][number] = 1;
            }
        }
    }
    fillup(board, rowNums, colNums, boxNums, 0, 0);
}


int main(void) {
    int i, j;
    char **board = malloc(9 * sizeof(char *));
    board[0] = malloc(9 * sizeof(char));
    board[0][0] = '5';
    board[0][1] = '3';
    board[0][2] = '.';
    board[0][3] = '.';
    board[0][4] = '7';
    board[0][5] = '.';
    board[0][6] = '.';
    board[0][7] = '.';
    board[0][8] = '.';

    board[1] = malloc(9 * sizeof(char));
    board[1][0] = '6';
    board[1][1] = '.';
    board[1][2] = '.';
    board[1][3] = '1';
    board[1][4] = '9';
    board[1][5] = '5';
    board[1][6] = '.';
    board[1][7] = '.';
    board[1][8] = '.';

    board[2] = malloc(9 * sizeof(char));
    board[2][0] = '.';
    board[2][1] = '9';
    board[2][2] = '8';
    board[2][3] = '.';
    board[2][4] = '.';
    board[2][5] = '.';
    board[2][6] = '.';
    board[2][7] = '6';
    board[2][8] = '.';

    board[3] = malloc(9 * sizeof(char));
    board[3][0] = '8';
    board[3][1] = '.';
    board[3][2] = '.';
    board[3][3] = '.';
    board[3][4] = '6';
    board[3][5] = '.';
    board[3][6] = '.';
    board[3][7] = '.';
    board[3][8] = '3';

    board[4] = malloc(9 * sizeof(char));
    board[4][0] = '4';
    board[4][1] = '.';
    board[4][2] = '.';
    board[4][3] = '8';
    board[4][4] = '.';
    board[4][5] = '3';
    board[4][6] = '.';
    board[4][7] = '.';
    board[4][8] = '1';

    board[5] = malloc(9 * sizeof(char));
    board[5][0] = '7';
    board[5][1] = '.';
    board[5][2] = '.';
    board[5][3] = '.';
    board[5][4] = '2';
    board[5][5] = '.';
    board[5][6] = '.';
    board[5][7] = '.';
    board[5][8] = '6';

    board[6] = malloc(9 * sizeof(char));
    board[6][0] = '.';
    board[6][1] = '6';
    board[6][2] = '.';
    board[6][3] = '.';
    board[6][4] = '.';
    board[6][5] = '.';
    board[6][6] = '2';
    board[6][7] = '8';
    board[6][8] = '.';

    board[7] = malloc(9 * sizeof(char));
    board[7][0] = '.';
    board[7][1] = '.';
    board[7][2] = '.';
    board[7][3] = '4';
    board[7][4] = '1';
    board[7][5] = '9';
    board[7][6] = '.';
    board[7][7] = '.';
    board[7][8] = '5';

    board[8] = malloc(9 * sizeof(char));
    board[8][0] = '.';
    board[8][1] = '.';
    board[8][2] = '.';
    board[8][3] = '.';
    board[8][4] = '8';
    board[8][5] = '.';
    board[8][6] = '.';
    board[8][7] = '7';
    board[8][8] = '9';

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    solveSudoku(board, 9, 9);
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    return;
}
