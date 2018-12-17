#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    int **height = calloc(matrixRowSize, sizeof(int *));
    for (int i = 0; i < matrixRowSize; i++) {
        *(height + i) = calloc(matrixColSize, sizeof(int));
    }
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                int currentHeight = 0;
                for (int k = i; k < matrixRowSize && matrix[k][j] == '1'; k++, currentHeight++) {}
                height[i][j] = currentHeight;
            }
        }
    }
    int maxArea = 0;
    int tmpMaxArea;
    int curArea, maxHeight;
    for (int i = 0; i < matrixRowSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            if (matrix[i][j] == '1') {
                tmpMaxArea = height[i][j];
                maxHeight = height[i][j];
                for (int k = j+1; k < matrixColSize && height[i][k] > 0; k++) {
                    maxHeight = (height[i][k] < maxHeight ? height[i][k] : maxHeight);
                    curArea = (k - j + 1) * maxHeight;
                    tmpMaxArea = (curArea > tmpMaxArea ? curArea : tmpMaxArea);
                }
                maxArea = (tmpMaxArea > maxArea ? tmpMaxArea : maxArea);
            }
        }
    }

    return maxArea;
}


/* ./test 11111111 11111110 11111110 11111000 01111000 */
int main(int argc, char **argv)
{
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
    printf("%d\n", maximalRectangle(argv + 1, argc - 1, strlen(argv[1])));
    return 0;
}
