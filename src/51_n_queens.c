#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char*** solveNQueens(int n, int* returnSize) {
    char *string = calloc(n+1, sizeof(char));
    char **tmpResult = calloc(1024, sizeof(char *));
    for (int i = 0; i < 1024; i++) {
        *(tmpResult + i) = calloc(n, sizeof(char));
    }
    for (int i = 0; i < n; i++) {
        string[i] = 'a' + i;
    }
    *returnSize = 0;
    nqueens(string, n, 0, tmpResult, returnSize);

    char ***result = calloc(*returnSize, sizeof(char **));
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = calloc(n, sizeof(char *));
        for (int j = 0; j < n; j++) {
            *(*(result + i) + j) = calloc(n + 1, sizeof(char));
            memset(*(*(result + i) + j), '.', n);
        }
    }
    for (int i = 0; i < *returnSize; i++) {
        convert(tmpResult[i], result[i], n);
    }
    free(string);
    for (int i = 0; i < 1024; i++) {
        free(*(tmpResult + i));
    }
    free(tmpResult);
    return result;
}


void swap(char a[], long i, long j) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


bool has_a_queen_in_diagonal(const char queens[], long len, long i) {
    char curr_col = queens[i];
    char left_col = curr_col - 1;
    char right_col = curr_col + 1;
    for (long row = i + 1; row < len; row += 1) {
        if (queens[row] == left_col || queens[row] == right_col) {
            return true;
        }
        left_col -= 1;
        right_col += 1;
    }
    return false;
}


bool threaten_each_other_diagonally(char queens[], long len) {
    for (long i = 0; i < len; i += 1) {
        // for each queen in row i, check rows i+1 onwards,
        // on both left (-=1) and right (+=1) side, if there
        // is a queen in that column.
        if (has_a_queen_in_diagonal(queens, len, i)) {
            return true;
        }
    }
    return false;
}


void nqueens(char *queens, long n, long row, char **result, int *count) {
    if (row == n - 1) {
        if (!threaten_each_other_diagonally(queens, n)) {
            strcpy(*(result + *count), queens);
            (*count)++;
            return;
        }
    }
    if (!threaten_each_other_diagonally(queens, row)) {
        nqueens(queens, n, row + 1, result, count);
    }
    for (long i = row + 1; i < n; i += 1) {
        swap(queens, row, i);
        if (!threaten_each_other_diagonally(queens, row)) {
            nqueens(queens, n, row + 1, result, count);
        }
        swap(queens, i, row);
    }
}

// convert the 2d result of 'bdac' into 3d result
void convert(char *tmpResult, char **result, int n) {
    for (int i = 0; i < n; i++) {
        result[i][tmpResult[i] - 'a'] = 'Q';
    }
}


int main() {
    int n = 6;
    int returnSize;
    char ***result = solveNQueens(n, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < n; j++) {
            printf("%s\n",result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < n; j++) {
            free(*(*(result + i) + j));
        }
        free(*(result + i));
    }
    free(result);
}
