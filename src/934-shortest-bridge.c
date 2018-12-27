#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int shortestBridge(char** A, int ARowSize, int AColSize) {
    bool marked1 = false;
    bool marked2 = false;
    int island1Num = 0;
    int island2Num = 0;
    int **island1Pos = calloc(3000, sizeof(int*));
    int **island2Pos = calloc(3000, sizeof(int*));
    for (int i = 0; i < ARowSize; i++) {
        if (marked1 && marked2) {
                break;
        }
        for (int j = 0; j < AColSize; j++) {
            if (marked1 && marked2) {
                break;
            }
            if (A[i][j] == '1') {
                if (!marked1) {
                mark(A, i, j, ARowSize, AColSize, &island1Num, island1Pos, '2', '1');
                marked1 = true;
                }
                else if (!marked2){
                    mark(A, i, j, ARowSize, AColSize, &island2Num, island2Pos, '2', '1');
                    marked2 = true;
                }
            }
        }
    }
    int tmp;
    int result = INT_MAX;
    for (int i = 0; i < island1Num; i++) {
        for (int j = 0; j < island2Num; j++) {
            tmp = abs(island1Pos[i][0] - island2Pos[j][0]) + abs(island1Pos[i][1] - island2Pos[j][1]) - 1;
            result = result > tmp ? tmp : result;
            if (result == 1) {
                return result;
            }
        }
    }
    return result;
}


void mark(char** map, int i, int j, int row, int col, int* islandNum, int **pos, char target, char source) {
    map[i][j] = target;
    pos[*islandNum] = calloc(2, sizeof(int));
    pos[*islandNum][0] = i;
    pos[*islandNum][1] = j;
    (*islandNum) += 1;
    if (i < row-1 && map[i+1][j] == source) {
        mark(map, i+1, j, row, col, islandNum, pos, target, source);
    }
    if (i > 0 && map[i-1][j] == source) {
        mark(map, i-1, j, row, col, islandNum, pos, target, source);
    }
    if (j < col-1 && map[i][j+1] == source) {
        mark(map, i, j+1, row, col, islandNum, pos, target, source);
    }
    if (j > 0 && map[i][j-1] == source) {
        mark(map, i, j-1, row, col, islandNum, pos, target, source);
    }
}



/* ./test 11111 10001 10101 10001 11111 */
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
    printf("%d\n", shortestBridge(argv + 1, argc - 1, col_size));
    return 0;
}
