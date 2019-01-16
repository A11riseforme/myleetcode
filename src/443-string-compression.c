#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compress(char* chars, int charsSize) {
    int start = 0;
    int result = 1;
    if (charsSize == 1) {
        return result;
    }
    for (int i = 1; i < charsSize; ++i) {
        while (chars[i] == chars[start] && i < charsSize) {
            ++i;
        }
        int num = i - start;
        if (num == 1) {
            chars[result++] = chars[i];
            start = i;
            continue;
        }
        char *number = malloc(11 * sizeof(char));
        sprintf(number, "%d", num);
        int j = 0;
        while (j < strlen(number)) {
            chars[result++] = number[j++];
        }
        free(number);
        chars[result++] = chars[i];
        start = i;
    }
    if(start == charsSize - 1) {
        return result;
    }
    return result - 1;
}


int main() {
    char chars[] = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int n = compress(chars, 7);
    for (int i = 0; i < n; ++i) {
        printf("%c ", chars[i]);
    }
    return 0;
}
