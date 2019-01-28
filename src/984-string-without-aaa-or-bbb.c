#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char* strWithout3a3b(int A, int B) {
    char a = 'a';
    char b = 'b';
    if (B > A) {
        a = 'b';
        b = 'a';
        A ^= B ^= A ^= B;
    }
    char *result = malloc((A + B + 1) * sizeof(char));
    int i = 0;
    while (A-- > 0) {
        result[i++] = a;
        if (A > B) {
            result[i++] = a;
            A--;
        }
        if (B-- > 0) {
            result[i++] = b;
        }
    }
    result[i] = '\0';
    return result;
}


int main(int argc, char** argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test A B\n");
        exit(-1);
    }
    char *result = strWithout3a3b(atoi(argv[1]), atoi(argv[2]));
    printf("%s", result);
    free(result);
    return 0;
}
