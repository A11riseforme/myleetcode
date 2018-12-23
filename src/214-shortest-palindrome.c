#include <stdio.h>
#include <stdlib.h>

char* shortestPalindrome(char* s) {
    int len = strlen(s);
    // make a reversed string for reference.
    char *sRef = malloc((len + 1) * sizeof(char));
    sRef[len] = '\0';
    int i;
    for (i = 0; i < len; i++) {
        sRef[len - 1 - i] = s[i];
    }
    int pos = 0;
    // brute force.
    for (i = 0; i < len; i++) {
        if (strncmp(s, sRef + len - 1 - i, i + 1) == 0) {
            pos = i;
        }
    }
    int newLen = 2 * len - pos - 1;
    char *result = malloc((newLen + 1) * sizeof(char));
    int j = 0;
    for (i = len - 1; i > pos; i--) {
        result[j++] = s[i];
    }
    // using memcpy instead of strncpy to skip assigning last char to '\0'
    memcpy(result + j, s, len + 1);
    free(sRef);
    return result;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }

    printf("%s\n", shortestPalindrome(argv[1]));
    return 0;
}
