#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b)) ? (a) : (b)

int longestValidParentheses(char* s) {
    int len = strlen(s);
    int result = 0;
    int *stk = malloc((len + 1) * sizeof(int));
    int k = 0;
    stk[k++] = -1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '(') {
            stk[k++] = i;
        } else {
            --k;
            if (k == 0) {
                stk[k++] = i;
            } else {
                result = MAX(result, i - stk[k - 1]);
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string of parentheses\n");
        exit(-1);
    }

    printf("%d", longestValidParentheses(argv[1]));
}
