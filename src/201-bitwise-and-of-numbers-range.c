#include <stdio.h>
#include <stdlib.h>

int rangeBitwiseAnd(int m, int n) {
    int i = 0;
    // searching the left most common bits length.
    while (m != n) {
        m >>= 1;
        n >>= 1;
        ++i;
    }
    return (m << i);
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test left right\n");
        exit(-1);
    }
    printf("%d", rangeBitwiseAnd(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
