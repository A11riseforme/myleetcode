#include <stdio.h>
#include <stdlib.h>

// straight-forward solution.
int hammingDistance(int x, int y) {
    char *xString = calloc(32, sizeof(char));
    char *yString = calloc(32, sizeof(char));
    int tmp;
    for (int i = 31; i >= 0; i--) {
        tmp = x % 2;
        xString[i] = tmp + '0';
        x /= 2;
    }
    for (int i = 31; i >= 0; i--) {
        tmp = y % 2;
        yString[i] = tmp + '0';
        y /= 2;
    }
    int result = 0;
    for (int i = 0; i < 32; i++) {
        result += xString[i] == yString[i] ? 0 : 1;
    }
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
