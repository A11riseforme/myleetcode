#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int compare_ints(const void* a, const void* b) {
    /*
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    */
    return *(const int*)a - *(const int*)b;
}

int numRescueBoats(int* people, int peopleSize, int limit) {
    qsort(people, peopleSize, sizeof(people[0]), compare_ints);
    int i = 0, j = peopleSize - 1;
    int result = 0;
    while (i <= j) {
        if (people[i] + people[j] <= limit) {
            ++i;
            --j;
            ++result;
        } else {
            --j;
            ++result;
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int people[] = {3, 2, 2, 1};
    printf("%d\n", numRescueBoats(people, sizeof(people) / sizeof(people[0]), 3));
    return 0;
}

