#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// can treat matrix as a 1d sorted array and apply binary search.
// or do binary search on matrix[][0](first column), then do binary search on matrix[i][](one row)
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    for (int i = 0; i < matrixRowSize; i++) {
        if ((target >= matrix[i][0] && i == matrixRowSize - 1) ||
            (target >= matrix[i][0] && target < matrix[i + 1][0])) {
            if (target <= matrix[i][matrixColSize - 1]) {
                for (int j = 0; j < matrixColSize; j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                return false;
            }
        }
    }
    return false;
}


int main() {
    int **matrix = calloc(3, sizeof(int *));
    int a[] = {1, 3, 5, 7};
    int b[] = {10, 11, 16, 20};
    int c[] = {23, 30, 34, 50};
    *(matrix + 0 ) = a;
    *(matrix + 1 ) = b;
    *(matrix + 2 ) = c;
    int target = 16;
    if (searchMatrix(matrix, 3, 4, target)) {
        printf("%d is contained in the matrix", target);
    } else {
        printf("%d is not contained in the matrix", target);
    }
    free(matrix);
}
