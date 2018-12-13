#include <stdio.h>

long uniquePaths(int m, int n) {
    int max = m > n ? m-1 : n-1;
    int min = m + n - 2 - max;
    int totalDirection = max + min;
    long paths = 1;
    for (int i = totalDirection; i > max; i--) {
        paths *= i;
    }
    for (int i = min; i > 0; i--) {
        paths /= i;
    }
    return paths;
}


int main() {
    printf("%ld", uniquePaths(7, 3));
}
