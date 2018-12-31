#include <stdio.h>
#include <stdlib.h>

// straight-forward solution.
int hammingDistance(int x, int y) {
    int *xString = calloc(32, sizeof(int));
    int *yString = calloc(32, sizeof(int));
    int tmp;
    for (int i = 31; x != 0; i--) {
        tmp = x % 2;
        xString[i] = tmp;
        x /= 2;
    }
    for (int i = 31; y != 0; i--) {
        tmp = y % 2;
        yString[i] = tmp;
        y /= 2;
    }
    int result = 0;
    for (int i = 0; i < 32; i++) {
        result += xString[i] == yString[i] ? 0 : 1;
    }
    free(xString);
    free(yString);
    return result;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test num1 num2\n");
        exit(-1);
    }
    printf("%d", hammingDistance(atoi(argv[1]), atoi(argv[2])));
    return 0;
}
