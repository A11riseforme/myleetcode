#include <stdio.h>
#include <stdlib.h>

// dp
int numDecodings(char* s) {
    int mod = 1000000007;
    int sLen = strlen(s);
    // long instead of int to prevent overflow.
    long *result = malloc((sLen+1)*sizeof(long));
    result[0] = 1;
    result[1] = s[0] == '*' ? 9 : (s[0] == '0' ? 0 : 1);
    for (int i = 1; i < sLen; i++) {
        if (s[i] == '*') {
            result[i+1] = 9 * result[i];
            if (s[i-1] == '1') {
                result[i+1] = (result[i+1] + 9 * result[i-1]) % mod;
            } else if (s[i-1] == '2') {
                result[i+1] = (result[i+1] + 6 * result[i-1]) % mod;
            } else if (s[i-1] == '*') {
                result[i+1] = (result[i+1] + 15 * result[i-1]) % mod;
            }
        } else {
            result[i+1] = s[i] != '0' ? result[i] : 0;
            if (s[i-1] == '1') {
                result[i+1] = (result[i+1] + result[i-1]) % mod;
            } else if (s[i-1] == '2' && s[i] <= '6') {
                result[i+1] = (result[i+1] + result[i-1]) % mod;
            } else if (s[i-1] == '*') {
                result[i+1] = (result[i+1] + (s[i] <= '6' ? 2 : 1) * result[i-1]) % mod;
            }
        }
    }
    int res = result[sLen];
    free(result);
    return res;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string\n");
        exit(-1);
    }
    printf("%s has %d ways to decode", argv[1], numDecodings(argv[1]));
    return 0;
}
