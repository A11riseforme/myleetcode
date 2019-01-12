#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool isMatched(int a, int b, int n, int k) {
    // last n-1 digits in base k.
    a %= (int)pow(k, n - 1);
    // first n-1 digits in base k.
    b = (b - b % k) / k;
    return a == b;
}


bool dfs(int *used, int *pass, int matched, int totalP, int n, int k) {
    if (matched == totalP) {
        return true;
    }
    for (int i = 0; i < totalP; ++i) {
        if (used[i] == 0 && isMatched(pass[matched - 1], i, n, k)) {
            used[i] = 1;
            pass[matched] = i;
            if (dfs(used, pass, matched + 1, totalP, n, k)) {
                return true;
            }
            used[i] = 0;
        }
    }
    return false;
}


char* crackSafe(int n, int k) {
    int totalP = (int)pow(k, n);
    int *used = calloc(totalP, sizeof(int));
    int *pass = calloc(totalP, sizeof(int));
    for (int i = 0; i < totalP; ++i) {
        used[i] = 1;
        pass[0] = i;
        if (dfs(used, pass, 1, totalP, n, k)) {
            break;
        }
        used[i] = 0;
    }
    char *result = malloc((totalP + n) * sizeof(char));
    for (int i = 0; i < n; ++i) {
        result[i] = pass[0] / (int)pow(k, n - 1 - i) + '0';
        pass[0] %=  (int)pow(k, n - 1 - i);
    }
    for (int i = n; i < totalP + n - 1; i++) {
        result[i] = pass[i - n + 1] % k + '0';
    }
    result[totalP + n - 1] = '\0';
    free(pass);
    free(used);
    return result;
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test n k\n");
        exit(-1);
    }
    char *result = crackSafe(atoi(argv[1]), atoi(argv[2]));
    printf("%s\n", result);
    free(result);
    return 0;
}
