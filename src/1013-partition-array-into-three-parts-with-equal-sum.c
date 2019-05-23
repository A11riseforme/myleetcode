#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool canThreePartsEqualSum(int *A, int ASize) {
    int tmp = 0;
    int sum = 0;
    for (int i = 0; i < ASize; ++i) {
        sum += A[i];
    }
    if (sum % 3) {
        return false;
    }
    sum /= 3;
    for (int i = 0; i < ASize; ++i) {
        tmp += A[i];
        if (tmp == sum) {
            tmp = 0;
        }
    }
    return tmp == 0;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int A[] = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    printf("%s\n",
           canThreePartsEqualSum(A, sizeof(A) / sizeof(A[0])) ? "yes" : "no");
    return 0;
}