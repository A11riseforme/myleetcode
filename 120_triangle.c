#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    for (int i = 0; i < triangleRowSize; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (j == 0 || j == i) {
                triangle[i][j] += j == 0 ? triangle[i - 1][0] : triangle[i - 1][j - 1];
            } else {
                triangle[i][j] += triangle[i - 1][j - 1] > triangle[i - 1][j] ? triangle[i - 1][j] : triangle[i - 1][j - 1];
            }
        }
    }
    int result = triangle[triangleRowSize - 1][0];
    for (int i = 1; i < triangleRowSize; i++) {
        result = result < triangle[triangleRowSize - 1][i] ? result : triangle[triangleRowSize - 1][i];
    }
    return result;
}


int main(void) {
    int i, row = 4;
    int **triangle = malloc(row * sizeof(int *));
    int *sizes = malloc(row * sizeof(int));
    for (i = 0; i < row; i++) {
        sizes[i] = i + 1;
        triangle[i] = malloc(sizes[i] * sizeof(int));
    }
    triangle[0][0] = 2;
    triangle[1][0] = 3;
    triangle[1][1] = 4;
    triangle[2][0] = 6;
    triangle[2][1] = 5;
    triangle[2][2] = 7;
    triangle[3][0] = 4;
    triangle[3][1] = 1;
    triangle[3][2] = 8;
    triangle[3][3] = 3;

    printf("%d\n", minimumTotal(triangle, row, sizes));
    for (int i = 0; i < row; i++) {
        free(*(triangle + i));
    }
    free(triangle);
}
