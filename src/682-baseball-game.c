#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int calPoints(char** ops, int opsSize) {
    int validPos = 0;
    int *validPoints = malloc(opsSize * sizeof(int));
    int result = 0;
    for (int i = 0; i < opsSize; ++i) {
        if (isdigit(ops[i][0]) || ops[i][0] == '-') {
            validPoints[validPos++] = atoi(ops[i]);
            result += validPoints[validPos - 1];
        } else if (ops[i][0] == 'C') {
            result -= validPoints[--validPos];
        } else if (ops[i][0] == 'D') {
            validPoints[validPos++] = 2 * validPoints[validPos - 1];
            result += 2 * validPoints[validPos - 2];
        } else {
            validPoints[validPos++] = validPoints[validPos - 1] + validPoints[validPos - 2];
            result += validPoints[validPos - 1];
        }
    }
    free(validPoints);
    return result;
}


int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }

    char **ops = malloc((argc - 1) * sizeof(char*));
    for (int i = 0; i < argc - 1; ++i) {
        ops[i] = argv[i + 1];
        printf("%s\n", ops[i]);
    }
    printf("%d\n", calPoints(ops, argc - 1));
    free(ops);
    return 0;
}
