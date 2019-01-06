#include <stdio.h>
#include <stdbool.h>

// a smarter algorithm.
bool detectCapitalUseSmart(char* word) {
    int count = 0;
    int len = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            count++;
        }
        len++;
    }
    // count == len : for string like "ASBUFIWAE"
    // count == 1 && isupper(word[0]) : for string like "Adsazhfngaqe"
    // count == 0 : for string like "asdfhpoiuawef"
    return (count == len) || (count == 1 && isupper(word[0])) || (count == 0);
}


bool detectCapitalUse(char* word) {
    bool firstCap = isupper(word[0]);
    if (firstCap) {
        if (isalpha(word[1])) {
            if (isupper(word[1])) {
                for (int i = 2; word[i] != '\0'; i++) {
                    if (!isupper(word[i])) {
                        return false;
                    }
                }
                return true;
            } else {
                for (int i = 2; word[i] != '\0'; i++) {
                    if (isupper(word[i])) {
                        return false;
                    }
                }
                return true;
            }
            return true;
        }
    }
    for (int i = 1; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("the usage of capitals is %s", detectCapitalUse(argv[1]) ? "right" : "not right");
    return 0;
}
