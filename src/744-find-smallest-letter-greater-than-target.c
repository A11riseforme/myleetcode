#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


char nextGreatestLetter(char* letters, int lettersSize, char target) {
    for (int i = 0; i < lettersSize; ++i) {
        if (letters[i] > target) {
            return letters[i];
        }
    }
    return letters[0];
}


int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number...\n");
        exit(-1);
    }
    */
    char letters[] = "cfj";
    printf("%c\n", nextGreatestLetter(letters, strlen(letters), 'd'));
    return 0;
}
