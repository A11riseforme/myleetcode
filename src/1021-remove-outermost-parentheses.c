#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

char* removeOuterParentheses(char* S) {
    char *result = malloc((strlen(S) + 1) * sizeof(char));
    int start = 0;
    int sum = 0;
    int n = 0;
    for (int i = 0; i < strlen(S); ++i) {
        sum += (S[i] == '(' ? 1 : -1);
        if (sum == 0) {
            for (int j = start + 1; j < i; ++j) {
                result[n++] = S[j];
            }
            start = i + 1;
        }
    }
    result[n] = '\0';
    return result;
}


int main(int argc, char **argv) {

    if (argc != 2 ) {
        fprintf(stderr, "Usage: ./test parenthesis_string...");
        exit(-1);
    }

    printf("%s\n", removeOuterParentheses(argv[1]));
    return 0;
}

