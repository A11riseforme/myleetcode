#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) {
        return -1;
    }
    if (arg1 > arg2) {
        return 1;
    }
    return 0;
}

int twoCitySchedCost(int (*costs)[2], int costsRowSize) {
    int *diff = malloc(costsRowSize * sizeof(int));
    int result = 0;
    for (int i = 0; i < costsRowSize; ++i) {
        result += costs[i][0];
        diff[i] = costs[i][1] - costs[i][0];
    }
    qsort(diff, costsRowSize, sizeof(diff[0]), compare_ints);
    for (int i = 0; i < costsRowSize / 2; ++i) {
        result += diff[i];
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int costs[][2] = {{10, 20}, {30, 200}, {400, 50}, {30, 20}};
    printf("%d\n", twoCitySchedCost(costs, sizeof(costs) / sizeof(costs[0])));
    return 0;
}

