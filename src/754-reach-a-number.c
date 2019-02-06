#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int reachNumber(int target) {
    /*
    int sum = 0;
    int k = 0;
    target = abs(target);
    while (sum < target) {
        sum += (++k);
    }
    */
    target = abs(target);
    int k = ceil(-0.5+0.5*sqrt(1.0+8*(long)target));
    long sum = (1+k)*k/2;
    int d = sum - target;
    if (d & 1) {
        return k + 1 + k % 2;
    }
    return k;
}


int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number \n");
        exit(-1);
    }

    printf("%d", reachNumber(atoi(argv[1])));
    return 0;
}
