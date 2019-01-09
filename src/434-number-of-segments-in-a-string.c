#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSegments(char* s) {
    int result = 0;
    while (*s != '\0') {
        if (*s != ' ' && (*(s + 1) == ' ' || *(s + 1) == '\0')) {
            result++;
        }
        s++;
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test \"string\"\n");
        exit(-1);
    }
    printf("%d", countSegments(argv[1]));
    return 0;
}
