#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* reverseWords(char* s) {
    int start, end;
    char tmp;
    for (int i = 0; s[i] != '\0'; ++i) {
        while (s[i] == ' ') {
            ++i;
        }
        start = i;
        while (s[i] != ' ' && s[i] != '\0') {
            ++i;
        }
        end = i - 1;
        while (start < end) {
            tmp = s[start];
            s[start++] = s[end];
            s[end--] = tmp;
        }
    }
    return s;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%s", reverseWords(argv[1]));
    return 0;
}
