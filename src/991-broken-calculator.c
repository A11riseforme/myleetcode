#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// y can divide by 2 if even, or plus 1 at anytime
// shortest path from y to x == shortest path from x to y
// always do division if possible.
int brokenCalc(int X, int Y) {
    int result = 0;
    while (Y > X) {
        // if odd, plus one then divide by 2
        if (Y & 1) {
            result += 2;
            Y = (Y + 1) / 2;
            // if even, divide by 2
        } else {
            ++result;
            Y /= 2;
        }
    }
    return result + X - Y;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test source target\n");
        exit(-1);
    }
    printf("%d", brokenCalc(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
