#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

long eval(char *string, int start, int end) {
    for (int i = start; i < end; i++) {
        if (string[i] == '+') {
            return eval(string, start, i - 1) + eval(string, i + 1, end);
        }
    }
    for (int i = end; i > start; i--) {
        if (string[i] == '-') {
            return eval(string, start, i - 1) - eval(string, i + 1, end);
        }
    }
    for (int i = start; i < end; i++) {
        if (string[i] == '*') {
            return eval(string, start, i - 1) * eval(string, i + 1, end);
        }
    }
    long result = 0;
    for (int i = start; i <= end; i++) {
        if (string[i] == ' ') {
            continue;
        }
        result = result * 10 + string[i] - '0';
    }
    return result;
}


void dfs(char *tmp, int index, int target, char **result, int *returnSize, int len) {
    if (index == len) {
        if (eval(tmp, 0, 2 * len) == target) {
            bool valid = true;
            if (tmp[0] == '0' && tmp[1] == ' ') {
                return;
            }
            for (int i = 1; i < 2 * len - 1; i++) {
                if ((tmp[i] == '+' || tmp[i] == '-' || tmp[i] == '*') && tmp[i + 1] == '0' && tmp[i + 2] == ' ') {
                    valid = false;
                    break;
                }
            }
            if (!valid) {
                return;
            }
            result[*returnSize] = malloc((2 * len + 2) * sizeof(char));
            int j = 0;
            for (int i = 0; i < 2 * len + 1; i++) {
                if (tmp[i] != ' ') {
                    result[*returnSize][j++] = tmp[i];
                }
            }
            result[(*returnSize)++][j] = '\0';
        }
        return;
    }
    tmp[index * 2 + 1] = '*';
    dfs(tmp, index + 1, target, result, returnSize, len);
    tmp[index * 2 + 1] = '+';
    dfs(tmp, index + 1, target, result, returnSize, len);
    tmp[index * 2 + 1] = '-';
    dfs(tmp, index + 1, target, result, returnSize, len);
    tmp[index * 2 + 1] = ' ';
    dfs(tmp, index + 1, target, result, returnSize, len);
    return;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** addOperators(char* num, int target, int* returnSize) {
    char **result = malloc(10000 * sizeof(char*));
    int len = strlen(num);
    if (len == 0) {
        return NULL;
    }
    if (len == 1 && target != num[0] - '0') {
        return NULL;
    }
    char *tmp = malloc((2 * len - 1) * sizeof(char));
    for (int i = 0; i < len; i++) {
        tmp[2 * i] = num[i];
    }
    *returnSize = 0;
    dfs(tmp, 0, target, result, returnSize, len - 1);
    free(tmp);
    return result;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string target\n");
        exit(-1);
    }
    int returnSize;
    char **result = addOperators(argv[1], atoi(argv[2]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}
