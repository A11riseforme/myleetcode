#include <stdio.h>
#include <stdbool.h>

void reverseWords(char *s) {
    int i = 0, j = 0;
    while (s[i] != '\0') {
        while (s[i] == ' ') {
            i++;
        }
        if (s[i] == '\0') {
            break;
        }
        while (s[i] != '\0' && s[i] != ' ') {
            s[j++] = s[i++];
        }
        s[j++] = s[i];
    }
    s[j] = '\0';
    s[--j] = '\0';
    reverse(s, 0, j - 1);

    for (i = 0, j = 0; s[i] != '\0';) {
        for (j = i; s[j] != '\0' && s[j] != ' '; j++) {}
        reverse(s, i, j - 1);
        for (i = j; s[i] != '\0' && s[i] == ' '; i++) {}
    }
}

void reverse(char * s, int start, int end) {
    while(start < end) {
        char tmp = s[start];
        s[start++] = s[end];
        s[end--] = tmp;
    }
}


// didn't use this function.

void myTrim(char *s) {
    int length = strlen(s);
    int i = 0;
    int j = length - 1;
    while (s[i] == ' ') {
        s[i++] = '\0';
    }
    if (i == length) {
        return;
    }
    while (s[j] == ' ') {
        j--;
    }
    strncpy(s, s + i, j - i + 1);
    memset(s + j - i + 1, 0, length - j + i);
    j = 0;
    for (i = 0; i < strlen(s); i++, j++) {
        while (s[i] == ' ' && s[i + 1] == ' ') {
            i++;
        }
        s[j] = s[i];
    }
    for (; j < strlen(s); j++) {
        s[j] = '\0';
    }
}


// test "the sky is blue"
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    reverseWords(argv[1]);
    printf("%s\n", argv[1]);
    return 0;
}
