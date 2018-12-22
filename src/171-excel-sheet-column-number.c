#include <stdio.h>
#include <stdlib.h>

int titleToNumber(char* s) {
    int num = 0;
    for (int i = 0; * (s + i) != '\0'; i += 1) {
        num *= 26;
        num += *(s + i) - 'A' + 1;
    }
    return num;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test ABC\n");
        exit(-1);
    }

    printf("%d\n", titleToNumber(argv[1]));
    return 0;
}
