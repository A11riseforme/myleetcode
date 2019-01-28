#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool judgeCircle(char* moves) {
    int x = 0, y = 0;
    for (int i = 0; moves[i] != '\0'; ++i) {
        if (moves[i] == 'U') {
            ++x;
            continue;
        }
        if (moves[i] == 'D') {
            --x;
            continue;
        }
        if (moves[i] == 'L') {
            --y;
            continue;
        }
        if (moves[i] == 'R') {
            ++y;
            continue;
        }
    }
    if (x == 0 && y == 0) {
        return true;
    }
    return false;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test instructions \n");
        exit(-1);
    }
    printf("%s\n", judgeCircle(argv[1]) ? "yes" : "no");
    return 0;
}
