#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool backspaceCompare(char* S, char* T) {
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
    return  tmp == 0;
}

int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2...\n");
        exit(-1);
    }

    printf("%s\n", backspaceCompare(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
