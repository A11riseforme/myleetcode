#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s) {
    int len = strlen(s);
    int left = 0;
    int right = len - 1;
    char tmp;
    while (left < right) {
        tmp = s[left];
        s[left++] = s[right];
        s[right--] = tmp;
    }
    return s;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test \" string \"\n");
        exit(-1);
    }
    char *result = reverseString(argv[1]);
    printf("%s\n", result);
    return 0;
}
