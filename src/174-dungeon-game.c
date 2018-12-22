#include <stdio.h>
#include <stdlib.h>

int calculateMinimumHP(int** dungeon, int dungeonRowSize, int *dungeonColSizes) {
    int r = dungeonRowSize;
    int c = *dungeonColSizes;
    int hpRequired;
    int hp[r][c]; // minimum hp required to get to this pos.
    hpRequired = 1 - dungeon[r - 1][c - 1];
    hp[r - 1][c - 1] = hpRequired > 1 ? hpRequired : 1;
    // update the last column.
    for (int i = r - 2; i >= 0; i--) {
        hpRequired = hp[i + 1][c - 1] - dungeon[i][c - 1];
        hp[i][c - 1] = hpRequired > 1 ? hpRequired : 1;
    }
    // update the last row.
    for (int i = c - 2; i >= 0; i--) {
        hpRequired = hp[r - 1][i + 1] - dungeon[r - 1][i];
        hp[r - 1][i] = hpRequired > 1 ? hpRequired : 1;
    }
    for (int i = r - 2; i >= 0; i--) {
        for (int j = c - 2; j >= 0; j--) {
            hpRequired = (hp[i + 1][j] < hp[i][j + 1] ? hp[i + 1][j] : hp[i][j + 1]) - dungeon[i][j];
            hp[i][j] = hpRequired > 1 ? hpRequired : 1;
        }
    }
    return hp[0][0];
}


int main(void) {
    int row_size = 3, col_size = 3;
    int i, j, **dungeon = malloc(row_size * sizeof(int *));
    for (i = 0; i < row_size; i++) {
        dungeon[i] = malloc(col_size * sizeof(int));
    }
#if 1
    dungeon[0][0] = 1;
    dungeon[0][1] = -3;
    dungeon[0][2] = 3;
    dungeon[1][0] = 0;
    dungeon[1][1] = -2;
    dungeon[1][2] = 0;
    dungeon[2][0] = -3;
    dungeon[2][1] = -3;
    dungeon[2][2] = -3;
#else
    dungeon[0][0] = 3;
    dungeon[0][1] = -20;
    dungeon[0][2] = 30;
    dungeon[1][0] = -3;
    dungeon[1][1] = 4;
    dungeon[1][2] = 0;
#endif

    printf("dungeon:\n");
    for (i = 0; i < row_size; i++) {
        for (j = 0; j < col_size; j++) {
            printf("%d ", dungeon[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", calculateMinimumHP(dungeon, row_size, &col_size));
    for (int i = 0; i < row_size; i++) {
        free(*(dungeon + i));
    }
    free(dungeon);
}
