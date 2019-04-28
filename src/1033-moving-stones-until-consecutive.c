#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numMovesStones(int a, int b, int c){
    int *result = malloc(2*sizeof(int));
    // make a > b > c
    if (a > c && c > b) {
        c ^= b ^= c ^= b;
    }
    if (b > a && a > c) {
        a ^= b ^= a ^= b;
    }
    if (b > c && c > a) {
        b ^= a ^= b ^= a;
        b ^= c ^= b ^= c;
    }
    if (c > b && b > a) {
        c ^= a ^= c ^= a;
    }
    if (c > a && a > b) {
        a ^= b ^= a ^= b;
        c ^= a ^= c ^= a;
    }
    if (a == b + 1 && b == c+1) {
        result[0] = 0;
        result[1] = 0;
    } else {
        if (a < b+3 || b < c+3) {
            result[0] = 1;
        } else {
            result[0] = 2;
        }
        result[1] = a - c - 2;
    }
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */

    int *result = numMovesStones(1,2,5);
    printf("%d %d\n", result[0], result[1]);
    return 0;
}