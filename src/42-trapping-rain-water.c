#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)

int trap(int* height, int heightSize) {
    if (heightSize == 0) {
        return 0;
    }
    int *leftMax = malloc(heightSize * sizeof(int*));
    int *rightMax = malloc(heightSize * sizeof(int*));
    leftMax[0] = height[0];
    for (int i = 1; i < heightSize; ++i) {
        leftMax[i] = MAX(leftMax[i - 1], height[i]);
    }
    rightMax[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; --i) {
        rightMax[i] = MAX(rightMax[i + 1], height[i]);
    }
    int result = 0;
    for (int i = 1; i < heightSize; ++i) {
        result += MIN(leftMax[i] - height[i], rightMax[i] - height[i]);
    }
    free(leftMax);
    free(rightMax);
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string number ...\n");
        exit(-1);
    }
    */
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    printf("%d\n", trap(height, sizeof(height) / sizeof(height[0])));
    return 0;
}
