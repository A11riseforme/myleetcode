#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    while (*t != '\0') {
        if (*s == '\0') {
            printf("here");
            return true;
        }
        while (*s != *t && *t != '\0') {
            t++;
        }
        if (*s == *t) {
            s++;
            t++;
            continue;
        }
        if (*t == '\0') {
            return false;
        }
    }
    if (*s != '\0') {
        return false;
    }
    return true;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2\n");
        exit(-1);
    }
    printf("%s", isSubsequence(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
