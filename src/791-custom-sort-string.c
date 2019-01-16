#include <stdio.h>
#include <stdlib.h>

char* customSortString(char* S, char* T) {
    int *pos = calloc(26, sizeof(int));
    for (int i = 0; S[i] != '\0'; ++i) {
        pos[S[i] - 'a'] = i + 1;
    }
    int *freq = calloc(26, sizeof(int));
    for (int i = 0; T[i] != '\0'; ++i) {
        freq[T[i] - 'a']++;
    }
    char *result = malloc(201 * sizeof(char));
    int len = 0;
    for (int i = 0; i < 26; ++i) {
        if (pos[i] == 0) {
            while(freq[i]--) {
                result[len++] = i + 'a';
            }
        }
    }
    for (int i = 0; S[i] != '\0'; ++i) {
        while(freq[S[i] - 'a']--) {
            result[len++] = S[i];
        }
    }
    result[len] = '\0';
    return result;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string 1 string2");
        exit(-1);
    }
    char *result = customSortString(argv[1], argv[2]);
    printf("%s", result);
    free(result);
    return 0;
}
