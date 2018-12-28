#include <stdio.h>
#include <stdlib.h>

int minDeletionSize(char** A, int ASize) {
    int len = strlen(A[0]);
    int result = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 1; j < ASize; j++) {
            if (A[j][i] < A[j - 1][i]) {
                result++;
                break;
            }
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test string1 string2 string3....\n");
        exit(-1);
    }
    printf("%d", minDeletionSize(argv + 1, argc - 1));
    return 0;
}
