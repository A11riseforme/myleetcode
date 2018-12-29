#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    for (int i = 0; i < matrixRowSize; i++) {
        if (matrix[i][0] == target || matrix[i][matrixColSize - 1] == target) {
            return true;
        } else if (matrix[i][0] < target && matrix[i][matrixColSize - 1] > target) {
            for (int j = 1; j < matrixColSize - 1; j++) {
                if (matrix[i][j] == target) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int **matrix = malloc(5 * sizeof(int*));
    int a[] = {1, 4, 7, 11, 15};
    int b[] = {2, 5, 8, 12, 19};
    int c[] = {3, 6, 9, 16, 22};
    int d[] = {10, 13, 14, 17, 24};
    int e[] = {18, 21, 23, 26, 30};
    matrix[0] = a;
    matrix[1] = b;
    matrix[2] = c;
    matrix[3] = d;
    matrix[4] = e;
    printf("%s", searchMatrix(matrix, 5, 5, 5) ? "yes" : "no");
    return 0;
}
