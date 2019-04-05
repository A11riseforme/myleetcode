#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// definitely memory leak, but hard to fix
char* countAndSay(int n) {
    char *result = malloc(50000 * sizeof(char));
    if (n == 1) {
        result[0] = '1';
        result[1] = '\0';
        return result;
    }
    char *last = countAndSay(n - 1);
    int j = 0;
    int count = 0;
    for (int i = 0; i < strlen(last); ++i) {
        count = 1;
        while (last[i] == last[i + 1]) {
            ++i;
            ++count;
        }
        result[j++] = count + '0';
        result[j++] = last[i];
    }
    result[j] = '\0';
    return result;
}

int main(int argc, char** argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }

    int result = countAndSay(atoi(argv[1]));
    printf("%s\n", result);
    return 0;
}
