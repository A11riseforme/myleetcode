#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

void dfs(int** image, int r, int c, int i, int j, int target, int origin) {
    if (i < 0 || i >= r || j < 0 || j >= c || image[i][j] != origin) {
        return;
    }
    image[i][j] = target;
    dfs(image, r, c, i + 1, j, target, origin);
    dfs(image, r, c, i - 1, j, target, origin);
    dfs(image, r, c, i, j + 1, target, origin);
    dfs(image, r, c, i, j - 1, target, origin);
    return;
}


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** floodFill(int** image, int imageRowSize, int imageColSize, int sr, int sc, int newColor, int** columnSizes, int* returnSize) {
    *returnSize = imageRowSize;
    *columnSizes = malloc(imageRowSize * sizeof(int));
    for (int i = 0; i < imageRowSize; ++i) {
        (*columnSizes)[i] = imageColSize;
    }
    if (image[sr][sc] == newColor) {
        return image;
    }
    dfs(image, imageRowSize, imageColSize, sr, sc, newColor, image[sr][sc]);
    return image;
}


int main(int argc, char** argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number1 number2 \n");
        exit(-1);
    }
    */
    int **image = malloc(3 * sizeof(int*));
    int a[] = {1, 1, 1};
    int b[] = {1, 1, 0};
    int c[] = {1, 0, 1};
    image[0] = a;
    image[1] = b;
    image[2] = c;
    int returnSize;
    int *columnSizes;
    int **result = floodFill(image, 3, 3, 1, 1, 2, &columnSizes, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        for (int j = 0; j < columnSizes[i]; ++j) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }
    free(result);
    return 0;
}
