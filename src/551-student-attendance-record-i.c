#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool checkRecord(char* s) {
    int As = 0;
    As += s[0] == 'A';
    As += s[1] == 'A';
    if (As > 1) {
        return false;
    }
    for (int i = 2; s[i] != '\0'; ++i) {
        As += s[i] == 'A';
        if (As > 1 || (s[i] == 'L' && s[i - 1] == 'L' && s[i - 2] == 'L')) {
            return false;
        }
    }
    return true;
}


int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string \n");
        exit(-1);
    }

    printf("%s", checkRecord(argv[1]) ? "yes" : "no");
    return 0;
}
