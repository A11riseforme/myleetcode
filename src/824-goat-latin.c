#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool isvowel(char c) {
    char lower = tolower(c);
    return (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u');
}

char* toGoatLatin(char* S) {
    char tmp;
    int as = 2;
    char *result = calloc(2048, sizeof(char));
    for (int i = 0; *S != '\0'; ++as) {
        if (isvowel(*S)) {
            while (*S != ' ' && *S != '\0') {
                result[i++] = *S++;
            }
            result[i++] = 'm';
            for (int j = 0; j < as; ++j) {
                result[i++] = 'a';
            }
            if (*S == ' ') {
                result[i++] = *S++;
                continue;
            } else {
                result[i] = '\0';
                break;
            }
        } else {
            tmp = *S++;
            while (*S != ' ' && *S != '\0') {
                result[i++] = *S++;
            }
            result[i++] = tmp;
            result[i++] = 'm';
            for (int j = 0; j < as; ++j) {
                result[i++] = 'a';
            }
            if (*S == ' ') {
                result[i++] = *S++;
                continue;
            } else {
                result[i] = '\0';
                break;
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test inputs...\n");
        exit(-1);
    }
    */
    char a[] = "I speak Goat Latin";
    char *result = toGoatLatin(a);
    printf("%s\n", result);
    free(result);
    return 0;
}
