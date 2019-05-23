#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typical stack simulation
bool backspaceCompare(char *S, char *T) {
    char *s = malloc((strlen(S) + 1) * sizeof(char));
    char *t = malloc((strlen(T) + 1) * sizeof(char));
    for (int i = 0;; ++S) {
        if (*S == '\0') {
            s[i] = '\0';
            break;
        }
        if (*S != '#') {
            s[i++] = *S;
        } else {
            --i;
            if (i < 0) {
                i = 0;
            }
        }
    }
    for (int i = 0;; ++T) {
        if (*T == '\0') {
            t[i] = '\0';
            break;
        }
        if (*T != '#') {
            t[i++] = *T;
        } else {
            --i;
            if (i < 0) {
                i = 0;
            }
        }
    }
    int tmp = strcmp(s, t);
    free(s);
    free(t);
    return tmp == 0;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    char *S = "ab#c";
    char *T = "ad#c";
    printf("%s\n", backspaceCompare(S, T) ? "yes" : "no");
    return 0;
}