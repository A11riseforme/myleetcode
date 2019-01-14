#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

bool isPrime(long num) {
    if (num == 1) {
        return false;
    }
    if (num == 2 || num == 3) {
        return true;
    }
    if ((num % 6 != 1) && (num % 6 != 5)) {
        return false;
    }
    for (long i = 5; i <= sqrt(num); i += 6) {
        if ((num % i == 0) || (num % (i + 2) == 0)) {
            return false;
        }
    }
    return true;
}


int minSteps(int n) {
    if (n == 1) {
        return 0;
    }
    if (isPrime(n)) {
        return n;
    }
    int result = INT_MAX;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            result = result > i * minSteps(n / i) ? i + minSteps(n / i) : result;
        }
    }
    return result;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }
    printf("%d", minSteps(atoi(argv[1])));
    return 0;
}
