#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int dis(int* point1, int* point2) {
    return (point1[0] - point2[0]) * (point1[0] - point2[0]) + (point1[1] - point2[1]) * (point1[1] - point2[1]);
}


int numberOfBoomerangs(int** points, int pointsRowSize, int pointsColSize) {
    int result = 0;
    for (int i = 0; i < pointsRowSize - 2; ++i) {
        for (int j = i + 1; j < pointsRowSize - 1; ++j) {
            for (int k = j + 1; k < pointsRowSize; ++k) {
                if (dis(points[i], points[j]) == dis(points[i], points[k])) {
                    result += 2;
                }
                if (dis(points[j], points[i]) == dis(points[j], points[k])) {
                    result += 2;
                }
                if (dis(points[k], points[i]) == dis(points[k], points[j])) {
                    result += 2;
                }
            }
        }
    }
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test ransomNote magazine \n");
        exit(-1);
    }
    */
    int **points = malloc(3 * sizeof(int*));
    int a[] = {0, 0};
    int b[] = {1, 0};
    int c[] = {2, 0};
    points[0] = a;
    points[1] = b;
    points[2] = c;
    printf("%d", numberOfBoomerangs(points, 3, 2));
    return 0;
}
