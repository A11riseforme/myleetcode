#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// self-explanatory
bool divisorGame(int N) { return !(N % 2); }

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    printf("%s\n", divisorGame(atoi(argv[1])) ? "yes" : "no");
    return 0;
}