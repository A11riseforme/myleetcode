#include <stdio.h>
#include <string.h>


int numDecodings(char* s) {
    int length = strlen(s);
    int ways = parseString(s, 0, length);
    return ways;
}

// very slow but intuitive recursive method.
// can boost using memoization or dp.
int parseStringSlow(char *s, int index, int length) {
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


// faster algorithm with dp.
int numDecodings(char* s) {
    int len = strlen(s);
    if (len == 0) {
        return 0;
    }
    // ways[i] is number of ways to decode up to pos i.
    int *ways = calloc(len, sizeof(int));
    // initialize the first two value
    ways[0] = s[0] <= '9' && s[0] > '0' ? 1 : 0;
    if (s[1] <= '9' && s[1] > '0') {
        ways[1] += ways[0];
    }
    int num = toNumber(s, 0, 2);
    if (num <= 26 && num >= 10) {
        ways[1] += 1;
    }
    // dp
    for (int i = 2; i < len; ++i) {
        if (s[i] <= '9' && s[i] > '0') {
            ways[i] += ways[i - 1];
        }
        num = toNumber(s, i - 1, 2);
        if (num <= 26 && num >= 10) {
            ways[i] += ways[i - 2];
        }
    }
    return ways[len - 1];
}


int main() {
    char *s = "13123";
    printf("%d", numDecodings(s));
}
