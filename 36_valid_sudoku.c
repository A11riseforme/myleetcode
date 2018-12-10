#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// a very elegant use of 3d array, it is so nice that I have to include this in my notes.
int isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    int rows[9][9] = {0}; //rows[5][0] means whether number 1('0'+1) in row 5 has appeared.
    int cols[9][9] = {0}; //cols[3][8] means whether number 9('8'+1) in col 3 has appeared.
    int blocks[3][3][9] = {0}; //blocks[0][2][5] means whether number '6' in block 0,2 (row 0~2,col 6~8) has appeared.
    for(int r = 0; r < 9; r++) //traverse board r,c
        for(int c = 0; c < 9; c++)
            if(board[r][c] != '.') { //skip all number '.'
                int number = board[r][c] - '1'; //calculate the number's index(board's number minus 1)
                if(rows[r][number]++)
                    return 0; //if the number has already appeared once, return false.
                if(cols[c][number]++)
                    return 0;
                if(blocks[r / 3][c / 3][number]++)
                    return 0;
            }
    return 1;
}

bool isValidRow_slow(char **board, int row) {
    int num[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for (int i = 0; i < 9; i++) {
        if (board[row][i] != '.') {
            int number = board[row][i] - '0';
            if (number > 10 || number < 1) {
                printf("number is %c\n", board[row][i]);
                return false;
            } else {
                if (num[number] != -1) {
                    printf("num[number] is %d when number = %d, i = %d\n", num[number], number, i);
                    return false;
                }
                num[number]++;
            }
        }
    }
    return true;
}

bool isValidColumn(char **board, int col) {
    int num[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for (int i = 0; i < 9; i++) {
        if (board[i][col] != '.') {
            int number = board[i][col] - '0';
            if (number > 10 || number < 1) {
                return false;
            } else {
                if (num[number] != -1) {
                    return false;
                }
                num[number]++;
            }
        }
    }
    return true;
}

bool isValidBox(char **board, int row, int col) {
    int num[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[3 * row + i][3 * col + j] != '.') {
                int number = board[3 * row + i][3 * col + j] - '0';
                if (number > 10 || number < 0) {
                    return false;
                } else {
                    if (num[number] != -1) {
                        return false;
                    }
                    num[number]++;
                }
            }
        }
    }
    return true;
}

bool isValidSudoku(char **board, int boardRowSize, int boardColSize) {
    for (int i = 0; i < 9; i++) {
        if (!isValidRow(board, i)) {
            printf("not valid row at %d\n", i);
            return false;
        }
    }
    for (int i = 0; i < 9; i++) {
        if (!isValidColumn(board, i)) {
            printf("not valid column at %d\n", i);
            return false;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!isValidBox(board, i, j)) {
                printf("not valid box at %d %d\n", i, j);
                return false;
            }
        }
    }
    return true;
}

int main() {
    char **sudoku = calloc(9, sizeof(char *));
    *(sudoku + 0) = "53..7....";
    *(sudoku + 1) = "6..195...";
    *(sudoku + 2) = ".98....6.";
    *(sudoku + 3) = "8...6...3";
    *(sudoku + 4) = "4..8.3..1";
    *(sudoku + 5) = "7...2...6";
    *(sudoku + 6) = ".6....28.";
    *(sudoku + 7) = "...419..5";
    *(sudoku + 8) = "....8..79";
    printf("it is a %s sudoku\n\n", isValidSudoku_slow(sudoku, 9, 9) ? "valid" : "invalid");

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c ", sudoku[i][j]);
        }
        printf("\n");
    }

    free(sudoku);
}
