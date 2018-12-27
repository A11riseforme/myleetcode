#include <stdio.h>
#include <stdlib.h>

int calculate(char* s) {
    int sLen = strlen(s);
    return evaluate(s, 0, sLen-1);
}

int evaluate(char* s, int start, int end) {\
    int multiPos = -1;
    int dividePos = -1;
    for (int i = end; i >= start; i--) {
        if (s[i] == '+') {
            return evaluate(s, start, i-1) + evaluate(s, i+1, end);
        }
        if (s[i] == '-') {
            return evaluate(s, start, i-1) - evaluate(s, i+1, end);
        }
        // record down the first * appears from the right.
        if (s[i] == '*' && multiPos == -1) {
            multiPos = i;
        }
        // record down the first / appears from the right.
        if (s[i] == '/' && dividePos == -1) {
            dividePos = i;
        }
    }
    // no + or - sign, only consists of * and /
    if (multiPos > dividePos) {
        return evaluate(s, start, multiPos-1) * evaluate(s, multiPos+1, end);
    }
    if (dividePos > multiPos) {
        return evaluate(s, start, dividePos-1) / evaluate(s, dividePos+1, end);
    }
    return atoi(s+start);
}


/* ./test 11111111 11111110 11111110 11111000 01111000 */
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%s = %d\n", argv[1], calculate(argv[1]));
    return 0;
}
