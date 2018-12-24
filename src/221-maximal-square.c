#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}


int maximalSquare(char** matrix, int matrixRowSize, int matrixColSize) {
    int maxSide = 0;
    for (int i = 0; i < matrixColSize; i++) {
        if (matrix[0][i] == '1') {
            maxSide = 1;
        }
    }
    for (int i = 0; i < matrixRowSize; i++) {
        if (matrix[i][0] == '1') {
            maxSide = 1;
        }
    }
    if (matrixRowSize == 1 || matrixColSize == 1) {
        return maxSide;
    }
    int currSide;
    for (int i = matrixRowSize - 2; i >= 0; i--) {
        for (int j = matrixColSize - 2; j >= 0; j--) {
            if (matrix[i][j] != '0') {
                currSide = min(matrix[i + 1][j] - '0', matrix[i][j + 1] - '0', matrix[i + 1][j + 1] - '0') + 1;
                maxSide = maxSide < currSide ? currSide : maxSide;
                matrix[i][j] = currSide + '0';
            }
        }
    }
    return maxSide * maxSide;
}


/* ./test 11111111 11111110 11111110 11111000 01111000 */
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test row1 row2...\n");
        exit(-1);
    }

    int i, j;
    int row_size = argc - 1;
    int col_size = strlen(argv[1]);
    for (i = 0; i < row_size; i++) {
        printf("%s\n", argv[i + 1]);
    }
    printf("%d\n", maximalSquare(argv + 1, argc - 1, strlen(argv[1])));
    return 0;
}
