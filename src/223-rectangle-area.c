#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

// cannot handle extreme case, leading to overflow.
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int oLength = max(min(C, G) - max(A, E), 0); // overlapping triangle's length along x-axis, if have.
    int oWidth = max(min(D, H) - max(B, F), 0); // overlapping triangle's width along y-axis, if have.
    return (C - A) * (D - B) + (G - E) * (H - F) - oLength * oWidth;
}


/* ./test 11111111 11111110 11111110 11111000 01111000 */
int main(int argc, char **argv) {
    if (argc != 9) {
        fprintf(stderr, "Usage: ./test A B C D E F G H\n");
        exit(-1);
    }

    int A = atoi(argv[1]);
    int B = atoi(argv[2]);
    int C = atoi(argv[3]);
    int D = atoi(argv[4]);
    int E = atoi(argv[5]);
    int F = atoi(argv[6]);
    int G = atoi(argv[7]);
    int H = atoi(argv[8]);
    printf("%d\n", computeArea(A, B, C, D, E, F, G, H));
    return 0;
}
