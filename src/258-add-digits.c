#include <stdio.h>
#include <stdlib.h>

// check https://en.wikipedia.org/wiki/Digital_root#Congruence_formula
int addDigits(int num) {
    return 1 + (num - 1) % 9;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("%d\n", addDigits(atoi(argv[1])));
    return 0;
}
