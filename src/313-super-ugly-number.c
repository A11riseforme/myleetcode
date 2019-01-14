#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) (a) < (b) ? (a) : (b)

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    int len = 1;
    int *result = malloc(n * sizeof(int));
    int *indexes  = calloc(primesSize, sizeof(int));
    result[0] = 1;
    for (int i = 1; i < n; ++i) {
        result[i] = INT_MAX;
        for (int j = 0; j < primesSize; ++j) {
            result[i] = MIN(result[i], primes[j] * result[indexes[j]]);
        }
        for(int j = 0; j < primesSize; ++j) {
            if(result[i] == primes[j] * result[indexes[j]]) {
                indexes[j]++;
            }
        }
    }
    return result[n - 1];
}


int main() {
    int n = 12;
    int primes[] = {2, 7, 13, 19};
    printf("%d", nthSuperUglyNumber(n, primes, sizeof(primes) / sizeof(primes[0])));
    return 0;
}
