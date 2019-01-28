#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* toLowerCase(char* str) {
    int len = strlen(str);
    char *result = malloc((len+1)*sizeof(char));
    memcpy(result, str, len+1);
    for (int i = 0; str[i] != '\0'; ++i) {
        if (isupper(str[i])) {
            result[i] += 32;
        }
    }
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    char *result = toLowerCase(argv[1]);
    printf("%s", result);
    free(result);
    return 0;
}
