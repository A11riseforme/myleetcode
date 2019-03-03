#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool validMountainArray(int* A, int ASize) {
    int i = 0;
    while (i < ASize - 1 && A[i] < A[i + 1]) {
        ++i;
    }
    if (i == 0 || i == ASize - 1) {
        return false;
    }
    while (i < ASize - 1 && A[i] > A[i + 1]) {
        ++i;
    }
    return i == ASize - 1;
}


int main(int argc, char **argv) {

    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number1 number2...\n");
        exit(-1);
    }
    */
    int nums[] = {0, 3, 2, 1};
    printf("%s\n", validMountainArray(nums, sizeof(nums) / sizeof(nums[0])) ? "yes" : "no");
    return 0;
}
