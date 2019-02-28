#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool rotateString(char* A, char* B) {
    int Alen = strlen(A);
    int Blen = strlen(B);
    if (Alen != Blen) {
        return false;
    }
    char *AA = malloc((2 * Alen + 1) * sizeof(char));
    memcpy(AA, A, Alen);
    memcpy(AA + Alen, A, Alen + 1);
    if (strstr(AA, B)) {
        return true;
    }
    return false;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test stringA stringB...\n");
        exit(-1);
    }

    printf("%s\n", rotateString(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
