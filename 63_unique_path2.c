#include <stdio.h>
#include <stdlib.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    int **pathMatrix = calloc(obstacleGridRowSize, sizeof(int *));
    for (int i = 0; i < obstacleGridRowSize; i++) {
        *(pathMatrix + i) = calloc(obstacleGridColSize, sizeof(int));
    }
    int i = 0;

    //initialize the paths number of the first row.
    for (i = 0; i < obstacleGridColSize; i++) {
        if (obstacleGrid[0][i] != 1) {
            pathMatrix[0][i] = 1;
        // once there is an obstacle, the paths number after this point is all zero.
        } else {
            break;
        }
    }
    for (int j = i; j < obstacleGridColSize; j++) {
        pathMatrix[0][i] = 0;
    }

    //initialize the paths number of the first column.
    for (i =0; i < obstacleGridRowSize; i++) {
        if (obstacleGrid[i][0] != 1) {
            pathMatrix[i][0] = 1;
        // once there is an obstacle, the paths number after this point is all zero.
        } else {
            break;
        }
    }
    for (int j = i; j < obstacleGridRowSize; j++) {
        pathMatrix[i][0] = 0;
    }

    for (int j = 1; j < obstacleGridRowSize; j++) {
        for (int k = 1; k < obstacleGridColSize; k++) {
            if (obstacleGrid[j][k] != 1) {
                pathMatrix[j][k] = pathMatrix[j-1][k] + pathMatrix[j][k-1];
            } else {
                pathMatrix[j][k] = 0;
            }
        }
    }
    return pathMatrix[obstacleGridRowSize-1][obstacleGridColSize-1];
}


int main() {
    int **obstacleGrid = calloc(3, sizeof(int *));
    int a[3] = {0,0,0};
    int b[3] = {0,1,0};
    int c[3] = {0,0,0};
    *(obstacleGrid + 0) = a;
    *(obstacleGrid + 1) = b;
    *(obstacleGrid + 2) = c;
    printf("there is/are %d path(s) from the start to the end",uniquePathsWithObstacles(obstacleGrid, 3, 3));
    free(obstacleGrid);
}
