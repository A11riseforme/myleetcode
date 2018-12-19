#include <stdio.h>
#include <stdlib.h>

#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'

/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n) {
    int pos[2] = {0,0};
    int **result = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(result + i) = calloc(n, sizeof(int));
    }
    char direction = RIGHT;
    for (int i = 1; i <= n * n; i++) {
        fillNumber(result, pos, &direction, n, i);
    }
    return result;
}


void fillNumber(int **matrix, int *pos, char *direction, int sideLength, int number) {
    matrix[pos[0]][pos[1]] = number;
    if (*direction == RIGHT && (pos[1] == sideLength-1 || matrix[pos[0]][pos[1]+1] != 0)) {
        *direction = DOWN;
    } else if (*direction == DOWN && (pos[0] == sideLength-1 || matrix[pos[0]+1][pos[1]] != 0)) {
        *direction = LEFT;
    } else if (*direction == LEFT && (pos[1] == 0 || matrix[pos[0]][pos[1] - 1] != 0)) {
        *direction = UP;
    } else if (*direction == UP && (matrix[pos[0]-1][pos[1]] != 0)) {
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
}


int main() {
    int **result = generateMatrix(5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%2d ",result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 5; i++) {
        free(*(result + i));
    }
    free(result);
}
