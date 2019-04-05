#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b))?(a):(b)

typedef struct Interval {
    int start;
    int end;
} interval;

int cmp(const void *a, const void *b) {
    return ((interval *) a)->start - ((interval *) b)->start;
}

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct Interval* merge(struct Interval* intervals, int intervalsSize, int* returnSize) {
    qsort(intervals, intervalsSize, sizeof(*intervals), cmp);
    interval *result = malloc(100 * sizeof(interval));
    *returnSize = 0;
    for (int i = 0; i < intervalsSize;) {
        int low = intervals[i].start;
        int high = intervals[i].end;
        while (i < intervalsSize && intervals[i].start <= high) {
            high = MAX(high, intervals[i].end);
            ++i;
        }
        result[*returnSize].start = low;
        result[*returnSize].end = high;
        ++(*returnSize);
    }
    return result;
}

//test 1 3 2 6 8 10 15 18
int main(int argc, char **argv) {

    if (argc < 2 || argc % 2 == 0) {
        fprintf(stderr, "Usage: ./test start0 end0 start1 end1...");
        exit(-1);
    }

    int i, returnSize = 0;
    struct Interval *intervals = malloc((argc - 1) / 2 * sizeof(struct Interval));
    struct Interval *p = intervals;
    for (i = 1; i < argc; i += 2) {
        p->start = atoi(argv[i]);
        p->end = atoi(argv[i + 1]);
        p++;
    }

    struct Interval *result = merge(intervals, (argc - 1) / 2, &returnSize);
    for (i = 0; i < returnSize; ++i) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }
    free(result);
    free(intervals);
    return 0;
}
