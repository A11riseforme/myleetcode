#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    return rec1[0] < rec2[2] && rec2[0] < rec1[2] && rec1[1] < rec2[3] && rec2[1] < rec1[3];
}


int main(int argc, char** argv) {
    int rec1[] = {0, 0, 2, 2};
    int rec2[] = {1, 1, 3, 3};
    printf("%s", isRectangleOverlap(rec1, 4, rec2, 4) ? "yes" : "no");
    return 0;
}
