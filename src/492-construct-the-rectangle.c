#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int side = sqrt(area);
    int *result = malloc(2 * sizeof(int));
    for (int i = side; i > 0; i--) {
        if (area % i == 0) {
            result[0] = area / i;
            result[1] = i;
            break;
        }
    }
    *returnSize = 2;
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test area\n");
        exit(-1);
    }
    int returnSize;
    int *result = constructRectangle(atoi(argv[1]), &returnSize);
    printf("%d %d", result[0], result[1]);
    free(result);
    return 0;
}
