#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


int findJudge(int N, int (*trust)[2], int trustRowSize) {
    if (trustRowSize == 0 && N == 1) {
        return 1;
    }
    int tmp = (N) * (N + 1) / 2;
    int scores[N + 1];
    bool *trusted = calloc((N + 1), sizeof(bool));
    for (int i = 1; i <= N; ++i) {
        scores[i] = tmp - i;
    }
    int result = -1;
    for (int i = 0; i < trustRowSize; ++i) {
        trusted[trust[i][0]] = true;
        scores[trust[i][1]] -= trust[i][0];
        if (scores[trust[i][1]]) {
            continue;
        }
        result = trust[i][1];
    }
    if (result != -1 && !trusted[result]) {
        free(trusted);
        return result;
    }
    free(trusted);
    return -1;
}

// a more concise algorithm
int findJudge(int N, int** trust, int trustRowSize, int *trustColSizes) {
    int *edges = calloc(N+1, sizeof(int));
    for (int i = 0; i < trustRowSize; ++i) {
        --edges[trust[i][0]];
        ++edges[trust[i][1]];
    }
    for (int i = 1; i <= N; ++i) {
        if (edges[i] == N-1) {
            free(edges);
            return i;
        }
    }
    free(edges);
    return -1;
}


int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */
    int trust[][2] = {{1, 3}, {1, 4}, {2, 3}, {2, 4}, {4, 3}};
    printf("%d\n", findJudge(4, trust, 5));
    return 0;
}
