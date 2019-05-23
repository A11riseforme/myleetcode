#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// would be perfect using unordered_set
// unfortunately, it is C.
int uniqueMorseRepresentations(char **words, int wordsSize) {
    char comp[26][6] = {".-",   "-...", "-.-.", "-..",  ".",    "..-.", "--.",
                        "....", "..",   ".---", "-.-",  ".-..", "--",   "-.",
                        "---",  ".--.", "--.-", ".-.",  "...",  "-",    "..-",
                        "...-", ".--",  "-..-", "-.--", "--.."};
    char str1[100], uniques[100][100], str3[100];
    int result, same;
    same = result = 0;
    for (int i = 0; i < wordsSize; i++) {
        strcpy(str3, "");
        strcpy(str1, words[i]);

        for (int j = 0; j < strlen(str1); j++) {
            strcat(str3, comp[str1[j] - 'a']);
        }
        for (int j = 0; j < result; j++) {
            if (strcmp(uniques[j], str3) == 0) {
                same = 1;
                break;
            }
        }
        if (!same) {
            strcpy(uniques[result++], str3);
        }
        same = 0;
    }
    return result;
}

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: ./test string1 string2 string3 ...\n");
        exit(-1);
    }

    char **words = malloc((argc - 1) * sizeof(char *));
    for (int i = 0; i < argc - 1; ++i) {
        words[i] = argv[i + 1];
    }
    printf("%d\n", uniqueMorseRepresentations(words, argc - 1));
    return 0;
}