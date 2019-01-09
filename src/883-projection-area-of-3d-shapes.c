#include <stdio.h>
#include <stdlib.h>

// reduce three for-loop to two.
int projectionArea(int** grid, int gridRowSize) {
    int result = 0;
    int max;
    for (int i = 0; i < gridRowSize; i++) {
        int max = grid[i][0];
        result += grid[i][0] == 0 ? 0 : 1;
        for (int j = 1; j < gridRowSize; j++) {
            max = max < grid[i][j] ? grid[i][j] : max;
            result += grid[i][j] == 0 ? 0 : 1;
        }
        result += max;
    }
    for (int i = 0; i < gridRowSize; i++) {
        int max = grid[0][i];
        for (int j = 1; j < gridRowSize; j++) {
            max = max < grid[j][i] ? grid[j][i] : max;
        }
        result += max;
    }
    return result;
}

int main() {
    int **grid = malloc(3 * sizeof(int*));
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    grid[0] = a;
    grid[1] = b;
    grid[2] = c;
    printf("%d", projectionArea(grid, 3));
    free(grid);
    return 0;
}
