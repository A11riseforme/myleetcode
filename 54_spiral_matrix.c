#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int pos[2] = {0,0};
    int number = matrixRowSize * matrixColSize;
    int *result = calloc(number, sizeof(int));
    char direction = RIGHT;
    for (int i = 0; i < number; i++) {
        result[i] = getNumber(matrix, pos, &direction, matrixRowSize, matrixColSize);
    }
    return result;
}

int getNumber(int **matrix, int *pos, char *direction, int matrixRowSize, int matrixColSize) {
    int result = matrix[pos[0]][pos[1]];
    matrix[pos[0]][pos[1]] = INT_MAX;
    if (*direction == RIGHT && (pos[1] == matrixColSize-1 || matrix[pos[0]][pos[1]+1] == INT_MAX)) {
        *direction = DOWN;
    } else if (*direction == DOWN && (pos[0] == matrixRowSize-1 || matrix[pos[0]+1][pos[1]] == INT_MAX)) {
        *direction = LEFT;
    } else if (*direction == LEFT && (pos[1] == 0 || matrix[pos[0]][pos[1] - 1] == INT_MAX)) {
        *direction = UP;
    } else if (*direction == UP && (matrix[pos[0]-1][pos[1]] == INT_MAX)) {
        *direction = RIGHT;
    }
    switch (*direction) {
        case UP:
            pos[0]--;
            break;
        case DOWN:
            pos[0]++;
            break;
        case LEFT:
            pos[1]--;
            break;
        case RIGHT:
            pos[1]++;
            break;
    }
    return result;
}


int main() {
    int **nums = calloc(3, sizeof(int *)); //{{1,2,3},{4,5,6},{7,8,9}};
    int a[] = {1,2,3};
    int b[] = {4,5,6};
    int c[] = {7,8,9};
    *(nums + 0) = a;
    *(nums + 1) = b;
    *(nums + 2) = c;
    int *result = spiralOrder(nums, 3, 3);
    for (int i = 0; i < 9; i++) {
        printf("%d ",result[i]);
    }
    free(result);
}
