#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int lines = 1, count = 0;
    for (int i = 0; S[i] != '\0'; ++i) {
        if (count + widths[S[i] - 'a'] <= 100) {
            count += widths[S[i] - 'a'];
        } else {
            ++lines;
            count = widths[S[i] - 'a'];
        }
    }
    int *result = malloc(2 * sizeof(int));
    *returnSize = 2;
    result[0] = lines;
    result[1] = count;
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test secret guess\n");
        exit(-1);
    }
    */
    int widths[] = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};
    char *S = "bbbcccdddaaa";
    int returnSize;
    int *result = numberOfLines(widths, 26, S, &returnSize);
    printf("%d %d\n", result[0], result[1]);
    free(result);
    return 0;
}
