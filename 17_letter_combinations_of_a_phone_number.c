#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    char letterMatrix[10][5] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char letterLength[10] = {1, 1, 3, 3, 3, 3, 3, 4, 3, 4};
    bool empty = true;
    int count = 1;
    int length = strlen(digits);
    for (int i = 0; i < length; i++) {
        int digit = digits[i] - '0';
        if (letterLength[digit] > 0) {
            empty = false;
            count *= letterLength[digit];
        }
    }
    if (empty) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = count;
    char **result = calloc(count, sizeof(char *));
    for (int i = 0; i < count; i++) {
        *(result + i) = calloc(length + 1, sizeof(char));
    }
    int blockLeap = count;
    int blockNum = 1;
    for (int i = 0; i < length; i++) {
        int currentDigit = digits[i] - '0';
        int n = letterLength[currentDigit];
        int letterLeap = blockLeap / n;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < blockNum; k++) {
                for (int l = 0; l < letterLeap; l++) {
                    result[l + j * letterLeap + k * blockLeap][i] = letterMatrix[currentDigit][j];
                }
            }
        }
        blockLeap /= n;
        blockNum *= n;
    }
    return result;
}

int main() {
    char num[] = "232";
    int n = 0;
    char **output = letterCombinations(num, &n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", *(output + i));
    }
}
