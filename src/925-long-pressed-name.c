#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool isLongPressedName(char* name, char* typed) {
    int nameLen = strlen(name);
    int typedLen = strlen(typed);
    int i = 0, j = 0;
    while (j < typedLen) {
        if(name[i] == typed[j]) {
            ++i;
            ++j;
        }
        while (j < typedLen && name[i] != typed[j]) {
            ++j;
        }
    }
    return i == nameLen;
}


int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test name typedname...\n");
        exit(-1);
    }

    printf("%s\n", isLongPressedName(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
