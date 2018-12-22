#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 筛法，sieve of Eratosthenes. https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
int countPrimes(int n) {
    if (n < 3) {
        return 0;
    }
    if (n == 3) {
        return 1;
    }
    int count = 2;
    bool *isPrime = malloc(sizeof(bool) * n);
    memset(isPrime, true, n);
    for (int i = 5; i < n; i += 6) {
        if (isPrime[i]) {
            count++;
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 7; i < n; i += 6) {
        if (isPrime[i]) {
            count++;
            for (int j = 2 * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    free(isPrime);
    return count;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%d\n", countPrimes(atoi(argv[1])));
    return 0;
}
