#include <stdio.h>
#include <string.h>


int numDecodings(char* s) {
    int length = strlen(s);
    int ways = parseString(s, 0, length);
    return ways;
}

// very slow but intuitive recursive method.
int parseString(char *s, int index, int length) {
    if (index == length - 1) {
        if (s[index] >= '1' && s[index] <= '9') {
            return 1;
        }
        return 0;
    }
    if (index == length - 2) {
        if (s[index] >= '1' && s[index] <= '9') {
            return parseString(s, index+1, length) + ((toNumber(s, index, 2) >= 10 && toNumber(s, index, 2) <= 26) ? 1 : 0);
        }
    }
    return ((s[index] >= '1' && s[index] <= '9') ? parseString(s, index+1, length) : 0) +
           ((toNumber(s, index, 2) >= 10 && toNumber(s, index, 2) <= 26) ? parseString(s, index+2, length) : 0);
}

int toNumber(char *s, int index, int length) {
    int number = 0;
    for (int i = 0; i < length; i++) {
        number *= 10;
        number += s[index+i] - '0';
    }
    return number;
}


int main() {
    char *s = "13123";
    printf("%d", numDecodings(s));
}
