#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int *ap = *(int **)a;
    int *bp = *(int **)b;
    return ap[1] - bp[1];
}


int findMinArrowShots(int** points, int pointsRowSize, int pointsColSize) {
    if (pointsRowSize == 0) {
        return 0;
    }
    // sort the arr wrt the horizontal end coordinates.
    qsort(points, pointsRowSize, sizeof(points[1]), cmp);
    int start = 0;
    int result = 0;
    for (int i = 0; i < pointsRowSize; i++) {
        if (points[i][0] > points[start][1]) {
            result++;
            start = i;
        }
    }
    return ++result;
}


int main() {
    int **points = malloc(4 * sizeof(int*));
    int a[] = {10, 16};
    int b[] = {2, 8};
    int c[] = {1, 6};
    int d[] = {7, 12};
    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = d;
    printf("%d", findMinArrowShots(points, 4, 2));
    free(points);
    return 0;
}
