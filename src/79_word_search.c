#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool search(char **board, int boardRowSize, int boardColSize, char *word, int index, int r, int c) {
    if (word[index] == '\0') {
        return true;
    } else if (r != -1 && c != -1) {
        if (r <= boardRowSize - 2 && board[r+1][c] == word[index]) {
            board[r+1][c] = '\0';
            if (search(board, boardRowSize, boardColSize, word, index+1, r+1, c)) {
                return true;
            }
            board[r+1][c] = word[index];
        }
        if (c <= boardColSize - 2 && board[r][c+1] == word[index]) {
            board[r][c+1] = '\0';
            if (search(board, boardRowSize, boardColSize, word, index+1, r, c+1)) {
                return true;
            }
            board[r][c+1] = word[index];
        }
        if (r >= 1 && board[r-1][c] == word[index]) {
            board[r-1][c] = '\0';
            if (search(board, boardRowSize, boardColSize, word, index+1, r-1, c)) {
                return true;
            }
            board[r-1][c] = word[index];
        }
        if (c >= 1 && board[r][c-1] == word[index]) {
            board[r][c-1] = '\0';
            if (search(board, boardRowSize, boardColSize, word, index+1, r, c-1)) {
                return true;
            }
            board[r][c-1] = word[index];
        }
        return false;
    } else {
        for (int i = 0; i < boardRowSize; i++) {
            for (int j = 0; j < boardColSize; j++) {
                if (word[0] == board[i][j]) {
                    board[i][j] = '\0';
                    if (search(board, boardRowSize, boardColSize, word, 1, i, j)) {
                        return true;
                    }
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
    return false;
}


bool exist(char** board, int boardRowSize, int boardColSize, char* word) {
    if (search(board, boardRowSize, boardColSize, word, 0, -1, -1)) {
        return true;
    }
    return false;
}


int main() {
    char **board = calloc(3, sizeof(char *));
    for (int i = 0; i < 3; i++) {
        *(board + i) = calloc(4, sizeof(char));
    }
    char a[4] = {'A','B','C','E'};
    char b[4] = {'S','F','C','S'};
    char c[4] = {'A','D','E','E'};
    memcpy(*board, a, 4);
    memcpy(*(board+1), b, 4);
    memcpy(*(board+2), c, 4);
    char *target = "ABCCED";
    if (exist(board, 3, 4, target)) {
        printf("found\n");
    } else {
    printf("not found\n");
    }
}
