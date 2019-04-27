#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>



int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }

    int result = countAndSay(atoi(argv[1]));
    printf("%s\n", result);
    return 0;
}