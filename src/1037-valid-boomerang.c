#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isBoomerang(int **points, int pointsSize, int *pointsColSize) {
    return (points[0][0] - points[1][0]) * (points[0][1] - points[2][1]) !=
           (points[0][0] - points[2][0]) * (points[0][1] - points[1][1]);
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    printf("I am too lazy to code the testcases\n");
    return 0;
}