#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int fib(int N) {
    int a = 0;
    int b = 1;
    if (N == 0) {
        return 0;
    }
    int result;
    --N;
    while (N--) {
        result = a+b;
        a = b;
        b = result;
    }
    return result;
}


int main() {
    printf("%d", fib(23));
    return 0;
}
