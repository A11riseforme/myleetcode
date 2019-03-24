#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool canThreePartsEqualSum(int* A, int ASize) {
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
    int nums[] = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    printf("%s", canThreePartsEqualSum(nums, sizeof(nums) / sizeof(nums[0])) ? "yes" : "no");
    return 0;
}
