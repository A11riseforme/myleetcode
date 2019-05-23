#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isRobotBounded(char *instructions) {
    int facing = 0; // 0-3: north, east, south, west;
    int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int x = 0, y = 0;
    for (int i = 0; instructions[i]; ++i) {
        if (instructions[i] == 'G') {
            x += dir[facing][0];
            y += dir[facing][1];
        } else if (instructions[i] == 'R') {
            facing = (facing + 1) % 4;
        } else {
            facing = (facing + 3) % 4;
        }
    }
    return (x == 0 && y == 0) || (facing);
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test command ...\n");
        exit(-1);
    }

    printf("%s\n", isRobotBounded(argv[1]) ? "yes" : "no");
    return 0;
}