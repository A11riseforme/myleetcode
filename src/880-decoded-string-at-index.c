#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decodeAtIndex(char* S, int K) {
    long len = 0;
    int number;
    int i;
    for (i = 0; len < K; i++) {
        if (isalpha(S[i])) {
            len++;
            continue;
        }
        number = S[i] - '0';
        len *= number;
    }
    char *result = calloc(2, sizeof(char));
    i--;
    for (; i >= 0; i--) {
        K %= len;
        if (K == 0 && isalpha(S[i])) {
            result[0] = S[i];
            break;
        }
        if (isdigit(S[i])) {
            len /= S[i] - '0';
        } else {
            len -= 1;
        }
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string K\n");
        exit(-1);
    }
    char *result = decodeAtIndex(argv[1], atoi(argv[2]));
    printf("%s\n", result);
    free(result);
    return 0;
}
