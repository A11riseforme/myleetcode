#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canTransform(char* start, char* end) {
    int i = 0;
    int j = 0;
    int len = strlen(start);
    while (i < len && j < len) {
        while (i < len && start[i] == 'X') {
            i++;
        }
        while (j < len && end[j] == 'X') {
            j++;
        }
        if (start[i] != end[j]) {
            return false;
        }
        if ((start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
            return false;
        }
        i++;
        j++;
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string1 string2\n");
        exit(-1);
    }
    printf("%s", canTransform(argv[1], argv[2]) ? "can" : "cannot");
    return 0;
}
