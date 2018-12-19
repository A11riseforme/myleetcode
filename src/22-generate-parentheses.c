#include <stdio.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** generateParenthesis(int n, int* returnSize) {
    char **result = calloc(1000000, sizeof(char *));
    char *tmp = calloc(2 * n + 1, sizeof(char));
    int left = n;
    int right = n;
    *returnSize = 0;
    addParentheses(result, left, right, returnSize, tmp, 0);
    return result;
}


void addParentheses(char **result, int left, int right, int *size, char *tmp, int pos) {
    if (left == 0 && right == 0) {
        tmp[pos] = '\0';
        *(result + (*size)) = calloc(pos + 1, sizeof(char));
        strcpy(*(result + (*size)), tmp);
        (*size)++;
        return;
    }
    if (left > 0) {
        *(tmp + pos) = '(';
        addParentheses(result, left - 1, right, size, tmp, pos + 1);
    }
    if (right > 0 && left < right) {
        *(tmp + pos) = ')';
        addParentheses(result, left, right - 1, size, tmp, pos + 1);
    }
}


int main() {
    int n = 4;
    int size;
    char **result = generateParenthesis(n, &size);
    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%s\n", *(result + i));
    }
}
