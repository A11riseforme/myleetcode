#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b)) ? (b) : (a);

int minCostClimbingStairs(int* cost, int costSize) {
    for (int i = 2; i < costSize; ++i) {
        cost[i] += MIN(cost[i - 1], cost[i - 2]);
    }
    return MIN(cost[costSize - 1], cost[costSize - 2]);
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string \n");
        exit(-1);
    }
    */
    int costs[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    printf("%d", minCostClimbingStairs(costs, sizeof(costs) / sizeof(costs[0])));
    return 0;
}
