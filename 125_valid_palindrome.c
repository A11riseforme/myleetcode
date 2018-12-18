#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool isValid(char c) {
    return isalpha(c) || (c >= '0' && c <= '9');
}


bool isPalindrome(char* s) {
    int length = strlen(s);
    int i = 0;
    int j = length - 1;
    while (i <= j) {
        if(!isValid(s[i])) {
            i += 1;
            continue;
        } else if (!isValid(s[j])) {
            j -= 1;
            continue;
        }
        if (tolower(s[i]) != tolower(s[j])) {
            return false;
        }
        i += 1;
        j -= 1;
    }
    return true;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("\"%s\" is %sa palindrome\n", argv[1], isPalindrome(argv[1]) ? "" : "not ");
    return 0;
}
