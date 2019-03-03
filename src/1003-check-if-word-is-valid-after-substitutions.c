#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// simulate stack
bool isValid(char* S) {
    char s[20000];
    int i;
    for (i = -1; *S != '\0'; ++S) {
        if (*S == 'c') {
            if (i >= 1 && s[i] == 'b' && s[i - 1] == 'a') {
                i -= 2;
            } else {
                return false;
            }
        } else {
            s[++i] = *S;
        }
    }
    return i == -1;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string...\n");
        exit(-1);
    }

    printf("%s\n", isValid(argv[1]) ? "yes" : "no");
    return 0;
}
