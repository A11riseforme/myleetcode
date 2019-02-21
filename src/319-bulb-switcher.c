#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// only the bulb number with odd number of factors will be left on.
// which are those perfect square numbers.
int bulbSwitch(int n) {
    return sqrt(n);
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%d\n", bulbSwitch(atoi(argv[1])));
    return 0;
}
