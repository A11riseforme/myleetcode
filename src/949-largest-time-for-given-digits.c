#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)

char* largestTimeFromDigits(int* A, int ASize) {
    int time = INT_MIN;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (j != i) {
                for (int k = 0; k < 4; ++k) {
                    if (k != i && k != j) {
                        int l = 6 - i - j - k;
                        int hours = 10 * A[i] + A[j];
                        int mins = 10 * A[k] + A[l];
                        if (hours < 24 && mins < 60) {
                            time = MAX(time, hours * 60 + mins);
                        }
                    }
                }
            }
        }
    }
    if (time != INT_MIN) {
        char *result = malloc(6 * sizeof(char));
        sprintf(result, "%02d:%02d", time / 60, time % 60);
        return result;
    }
    char *result = calloc(1, sizeof(char));
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }
    */

    int A[] = {1, 2, 3, 4};
    char *result = largestTimeFromDigits(A, sizeof(A) / sizeof(A[0]));
    printf("%s\n", result);
    free(result);
    return 0;
}
