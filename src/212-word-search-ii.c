#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool dfs(char** board, int boardRowSize, int boardColSize, char* word, int i, int j, int index) {
    if (word[index] == '\0') {
        board[i][j] = word[index - 1];
        return true;
    }
    char tmp = board[i][j];
    board[i][j] = '.';
    if (i > 0 && board[i - 1][j] == word[index]) {
        if (dfs(board, boardRowSize, boardColSize, word, i - 1, j, index + 1)) {
            board[i][j] = word[index - 1];
            return true;
        }
    }
    if (i < boardRowSize - 1 && board[i + 1][j] == word[index]) {
        if (dfs(board, boardRowSize, boardColSize, word, i + 1, j, index + 1)) {
            board[i][j] = word[index - 1];
            return true;
        }
    }
    if (j > 0 && board[i][j - 1] == word[index]) {
        if (dfs(board, boardRowSize, boardColSize, word, i, j - 1, index + 1)) {
            board[i][j] = word[index - 1];
            return true;
        }
    }
    if (j < boardColSize - 1 && board[i][j + 1] == word[index]) {
        if (dfs(board, boardRowSize, boardColSize, word, i, j + 1, index + 1)) {
            board[i][j] = word[index - 1];
            return true;
        }
    }
    board[i][j] = tmp;
    return false;
}


bool canFind(char** board, int boardRowSize, int boardColSize, char* word) {
    for (int i = 0; i < boardRowSize; i++) {
        for (int j = 0; j < boardColSize; j++) {
            if (board[i][j] == word[0]) {
                if (dfs(board, boardRowSize, boardColSize, word, i, j, 1)) {
                    return true;
                }
                board[i][j] = word[0];
            }
        }
    }
    return false;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findWords(char** board, int boardRowSize, int boardColSize, char** words, int wordsSize, int* returnSize) {
    char **result = malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    bool duplicate = false;
    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; j < *returnSize; j++) {
            if (strcmp(words[i], result[j]) == 0) {
                duplicate = true;
                break;
            }
        }
        if (duplicate) {
            duplicate = false;
            continue;
        }
        if (canFind(board, boardRowSize, boardColSize, words[i])) {
            result[(*returnSize)++] = words[i];
        }
    }
    return result;
}

int main() {
    int i;
#if 1
    int row = 4;
    int col = 4;
    char **board = malloc(row * sizeof(char *));
    board[0] = malloc(col);
    board[0][0] = 'o';
    board[0][1] = 'a';
    board[0][2] = 'a';
    board[0][3] = 'n';
    board[1] = malloc(col);
    board[1][0] = 'e';
    board[1][1] = 't';
    board[1][2] = 'a';
    board[1][3] = 'e';
    board[2] = malloc(col);
    board[2][0] = 'i';
    board[2][1] = 'h';
    board[2][2] = 'k';
    board[2][3] = 'r';
    board[3] = malloc(col);
    board[3][0] = 'i';
    board[3][1] = 'f';
    board[3][2] = 'l';
    board[3][3] = 'v';

    int size = 4;
    char **words = malloc(size * sizeof(char *));
    words[0] = malloc(5);
    strcpy(words[0], "oath");
    words[1] = malloc(5);
    strcpy(words[1], "pea");
    words[2] = malloc(5);
    strcpy(words[2], "eat");
    words[3] = malloc(5);
    strcpy(words[3], "rain");
#else
    int row = 2;
    int col = 2;
    char **board = malloc(row * sizeof(char *));
    board[0] = malloc(col);
    board[0][0] = 'a';
    board[0][1] = 'b';
    board[1] = malloc(col);
    board[1][0] = 'a';
    board[1][1] = 'a';

    int size = 7;
    char **words = malloc(size * sizeof(char *));
    words[0] = malloc(5);
    words[1] = malloc(5);
    words[2] = malloc(5);
    words[3] = malloc(5);
    words[4] = malloc(5);
    words[5] = malloc(5);
    words[6] = malloc(5);
    strcpy(words[0], "aba");
    strcpy(words[1], "baa");
    strcpy(words[2], "bab");
    strcpy(words[3], "aaab");
    strcpy(words[4], "aaa");
    strcpy(words[5], "aaaa");
    strcpy(words[6], "aaba");
#endif

    int count = 0;
    char **lists = findWords(board, row, col, words, size, &count);
    for (i = 0; i < count; i++) {
        printf("%s\n", lists[i]);
    }
    return 0;
}
