#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b))?(b):(a)

int maxCount(int m, int n, int (*ops)[2], int opsRowSize) {
    int width = m;
    int length = n;
    for (int i = 0; i < opsRowSize; ++i) {
        width = MIN(width, ops[i][0]);
        length = MIN(length, ops[i][1]);
    }
    return width * length;
}

int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test stringA stringB...\n");
        exit(-1);
    }
    */
    int ops[][2] = {{2, 2}, {3, 3}};
    printf("%d\n", maxCount(3, 3, ops, sizeof(ops) / sizeof(ops[0])));
    return 0;
}
