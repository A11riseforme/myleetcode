#include <stdio.h>
#include <stdlib.h>

// do not over think about it. 脑筋急转弯？
int findLUSlength(char* a, char* b) {
    int aLen = strlen(a);
    int bLen = strlen(b);
    if (aLen == bLen) {
        if (strcmp(a,b) == 0) {
            return -1;
        }
        return aLen;
    }
    return aLen > bLen ? aLen : bLen;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string string\n");
        exit(-1);
    }
    printf("%d", findLUSlength(argv[1], argv[2]));
}
