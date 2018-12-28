#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b)  ((a>b)?(a):(b))

int findMaxForm(char** strs, int strsSize, int m, int n) {
    int **result = calloc(m + 1, sizeof(int*));
    for (int i = 0; i < m + 1; i++) {
        result[i] = calloc(n + 1, sizeof(int));
    }
    for (int i = 0; i < strsSize; i++) {
        int zeroNum = 0;
        int oneNum = 0;
        for (int j = 0; strs[i][j] != '\0'; j++) {
            if (strs[i][j] == '0') {
                zeroNum++;
            } else {
                oneNum++;
            }
        }
        for (int a = m; a >= zeroNum; a--) {
            for (int b = n; b >= oneNum; b--) {
                result[a][b] = MAX(result[a][b], result[a - zeroNum][b - oneNum] + 1);
            }
        }
    }
    return result[m][n];
}

int main() {
    char **string = malloc(5 * sizeof(char*));
    string[0] = "10";
    string[1] = "0001";
    string[2] = "111001";
    string[3] = "1";
    string[4] = "0";
    printf("%d", findMaxForm(string, 5, 5, 3));
    free(string);
}
