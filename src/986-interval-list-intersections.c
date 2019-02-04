#include <stdio.h>

int main( int argc, char *argv[] )
{
	printf( "Hello World!\n" );
	
	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

typedef struct {
    int start;
    int end;
} Interval;

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* intervalIntersection(Interval* A, int ASize, Interval* B, int BSize, int* returnSize) {
    Interval *result = malloc(1000 * sizeof(Interval));
    int i = 0, j = 0;
    int low, high;
    *returnSize = 0;
    while (i < ASize && j < BSize) {
        low = A[i].start < B[j].start ? B[j].start : A[i].start;
        high = A[i].end < B[j].end ? A[i].end : B[j].end;
        if (low <= high) {
            result[(*returnSize)].start = low;
            result[(*returnSize)++].end = high;
        }
        if (A[i].end < B[j].end) {
            ++i;
        } else {
            ++j;
        }
    }
    return result;
}


int main(int argc, char** argv) {
    Interval *intervals1 = malloc(4 * sizeof(Interval));
    Interval *intervals2 = malloc(4 * sizeof(Interval));
    intervals1[0].start = 0;
    intervals1[0].end = 2;
    intervals1[1].start = 5;
    intervals1[1].end = 10;
    intervals1[2].start = 13;
    intervals1[2].end = 23;
    intervals1[3].start = 24;
    intervals1[3].end = 25;
    intervals2[0].start = 1;
    intervals2[0].end = 5;
    intervals2[1].start = 8;
    intervals2[1].end = 12;
    intervals2[2].start = 15;
    intervals2[2].end = 24;
    intervals2[3].start = 25;
    intervals2[3].end = 26;
    int returnSize;
    Interval *result = intervalIntersection(intervals1, 4, intervals2, 4, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("[%d,%d]\n", result[i].start, result[i].end);
    }
    free(result);
    free(intervals1);
    free(intervals2);
    return 0;
}
