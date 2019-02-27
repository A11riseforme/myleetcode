#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)<(b))?(a):(b)

int cmp(const void* elem1, const void* elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    return (f > s) - (f < s);
}


int distributeCandies(int* candies, int candiesSize) {
    qsort(candies, candiesSize, sizeof(candies[0]), cmp);
    int result = 1;
    for (int i = 1; i < candiesSize; ++i) {
        if (candies[i] != candies[i - 1]) {
            ++result;
        }
    }
    return MIN(result, candiesSize / 2);
}


int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */

    int candies[] = {1, 1, 2, 2, 3, 3};
    printf("%d\n", distributeCandies(candies, sizeof(candies) / sizeof(candies[0])));
    return 0;
}
