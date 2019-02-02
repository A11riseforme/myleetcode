#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MIN(a,b) ((a)>(b)) ? (b) : (a)

int countBinarySubstrings(char* s) {
    int *groups = malloc(50000*sizeof(int));
    groups[0] = 1;
    int size = 0;
    for (int i = 1; s[i] != '\0'; ++i) {
        if (s[i] != s[i-1]) {
            groups[++size] = 1;
        } else {
            ++groups[size];
        }
    }
    int result = 0;
    for (int i = 1; i <= size; ++i) {
        result += MIN(groups[i], groups[i-1]);
    }
    free(groups);
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%d", countBinarySubstrings(argv[1]));
    return 0;
}
