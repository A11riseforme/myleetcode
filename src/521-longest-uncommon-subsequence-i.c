#include <stdio.h>
#include <stdlib.h>

// do not over think about it. 脑筋急转弯？
int findLUSlength(char* a, char* b) {
    if (!strcmp(a, b)) {
        return -1;
    }
    return strlen(a) > strlen(b) ? strlen(a) : strlen(b);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string string\n");
        exit(-1);
    }
    printf("%d", findLUSlength(argv[1], argv[2]));
}
