#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double knightProbability(int N, int K, int r, int c) {
    if (K == 0) {
        if (r >= 0 && r < N && c >= 0 && c < N) {
            return 1.0;
        }
        return 0.0;
    }
    double **initial = calloc(N, sizeof(double*));
    for (int i = 0; i < N; i++) {
        initial[i] = calloc(N, sizeof(double));
    }

    initial[r][c] = 1.0;
    int dir[8][2] = {{1, 2}, {2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}};
    for (int i = 0; i < K; i++) {
        double **after = calloc(N, sizeof(double*));
        for (int i = 0; i < N; i++) {
            after[i] = calloc(N, sizeof(double));
        }
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int l = 0; l < 8; l++) {
                    int row = j + dir[l][0];
                    int col = k + dir[l][1];
                    if (row < 0 || row >= N || col < 0 || col >= N) {
                        continue;
                    }
                    after[row][col] += initial[j][k];
                }
            }
        }
        int **tmp = after;
        after = initial;
        initial = tmp;
    }
    double count = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            count += initial[i][j];
        }
    }
    return count / pow(8, K);
}

int main(int argc, char **argv) {
    if (argc != 5) {
        fprintf(stderr, "Usage: ./test N K r c\n");
        exit(-1);
    }
    printf("%lf", knightProbability(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
    return 0;
}
