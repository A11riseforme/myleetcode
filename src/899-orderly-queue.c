#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// when K = 1; partition S into two parts, and swap this two parts
// to make lexicographically smallest string.
char* orderlyQueue(char* S, int K) {
    if (K == 1) {
        int minPos = 0;
        int len = 1;
        for (int i = 1; S[i] != '\0'; i++) {
            len++;
            if (S[minPos] > S[i]) {
                minPos = i;
                continue;
            }
            // decide whether a smaller lexicographically string is possible
            // qaeraerdaawed: partition into qaeraerd, aawed is better than qaer, aerdaawed
            if (S[minPos] == S[i]) {
                for (int j = 1; S[i + j] != 0; j++) {
                    if (S[i + j] < S[minPos + j]) {
                        minPos = i;
                        break;
                    } else if (S[i + j] > S[minPos + j]) {
                        break;
                    }
                }
            }
        }
        char *result = malloc((len + 1) * sizeof(char));
        memcpy(result, S + minPos, len - minPos);
        memcpy(result + len - minPos, S, minPos);
        result[len] = '\0';
        return result;
    }
    // if K > 1, a string can be permutated into any order, so the
    // lexicographically smallest string is just to sort the string.
    int len = 0;
    int freq[26] = {0};
    for (int i = 0; S[i] != '\0'; i++) {
        len++;
        freq[S[i] - 'a']++;
    }
    char *result = malloc((len + 1) * sizeof(char));
    int pos = 0;
    for (int i = 0; i < 26; i++) {
        while (freq[i]-- > 0) {
            result[pos++] = i + 'a';
        }
    }
    result[pos] = '\0';
    return result;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string K\n");
        exit(-1);
    }
    char *result = orderlyQueue(argv[1], atoi(argv[2]));
    printf("%s", result);
    free(result);
    return 0;
}
