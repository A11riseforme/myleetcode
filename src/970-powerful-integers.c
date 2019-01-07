#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    // max power that y can raise up to. 
    double yPower = (y == 1) ? 1 : (int)(log(bound) / log(y));
    // max power that x can raise up to. 
    double xPower = (x == 1) ? 1 : (int)(log(bound) / log(x));
    int *freq = calloc(bound + 1, sizeof(int));
    for (int i = 0; i <= xPower; i++) {
        for (int j = 0; j <= yPower; j++) {
            if ((int)(pow(x, i) + pow(y, j)) <= bound) {
                freq[(int)(pow(x, i) + pow(y, j))]++;
            }
        }
    }
    *returnSize = 0;
    int *result = malloc(bound * sizeof(int));
    for (int i = 0; i <= bound; i++) {
        if (freq[i] != 0) {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: ./test x y bound\n");
        exit(-1);
    }
    int returnSize;
    int *result = powerfulIntegers(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
