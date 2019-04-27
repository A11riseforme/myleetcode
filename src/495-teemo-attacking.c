#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration){
    if (timeSeriesSize<1) {
        return 0;
    }
    int result = 0;
    int prev = timeSeries[0];
    for (int i = 1; i < timeSeriesSize; ++i) {
        if (prev+duration <= timeSeries[i]) {
            result += duration;
        } else {
            result += timeSeries[i]-prev;
        }
        prev = timeSeries[i];
    }
    return result+duration;
}

int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
   int timeSeries[] = {1,2};
   printf("%d\n", findPoisonedDuration(timeSeries, sizeof(timeSeries)/sizeof(timeSeries[0]), 2));
    return 0;
}