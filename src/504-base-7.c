#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

char* convertToBase7(int num) {
    char *tmp = malloc(20 * sizeof(char));
    bool negative = num < 0;
    num = abs(num);
    int i = 0, j = 0;
    do {
        tmp[i++] = num % 7 + '0';
        num /= 7;
    } while (num);
    char *result = malloc((i + 2) * sizeof(char));
    if (negative) {
        result[j++] = '-';
    }
    while (i) {
        result[j++] = tmp[--i];
    }
    result[j] = '\0';
    free(tmp);
    return result;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number...\n");
        exit(-1);
    }

    char *result = convertToBase7(atoi(argv[1]));
    printf("%s\n", result);
    free(result);
    return 0;
}
