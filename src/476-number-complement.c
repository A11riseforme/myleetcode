#include <stdio.h>
#include <stdlib.h>

int findComplement(int num) {
    long i = 1;
    while (i <= num) {
        i *= 2;
    }
    return i - num - 1;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test num\n");
        exit(-1);
    }
    printf("%d\n", findComplement(atoi(argv[1])));
    return 0;
}
