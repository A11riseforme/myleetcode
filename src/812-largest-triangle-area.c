#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// matrix calculation, or can use the Heron's formula
double calcArea(int** points, int i, int j, int k) {
    return fabs(0.5 * (points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1]
                 - points[i][0]*points[k][1] - points[j][0]*points[i][1] - points[k][0]*points[j][1]));
}


double largestTriangleArea(int** points, int pointsRowSize) {
    double result = INT_MIN;
    double tmpArea;
    for (int i = 0; i < pointsRowSize - 2; i++) {
        for (int j = i+1; j < pointsRowSize - 1; j++) {
            for (int k = i+2; k < pointsRowSize; k++) {
                tmpArea = calcArea(points, i, j, k);
                result = tmpArea > result ? tmpArea : result;
            }
        }
    }
    return result;
}

int main() {
    int **points = malloc(5*sizeof(int*));
    int a[] = {0,0};
    int b[] = {0,1};
    int c[] = {1,0};
    int d[] = {0,2};
    int e[] = {2,0};
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    points[4] = e;
    printf("biggest area is %.2lf", largestTriangleArea(points, 5));
    return 0;
}
