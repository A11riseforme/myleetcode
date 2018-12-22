#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isHappy(int n) {
    int m = generate(n);
    int count = 0;
    while (m != n) {
        if (m == 1) {
            return true;
        } else {
            count += 1;
            n = m;
            m = generate(n);
            if (m == n || count == 100) {
                return false;
            }
        }
    }
    return true;
}

int generate(int n) {
    int sum = 0;
    do {
        sum += (n % 10) * (n % 10);
        n /= 10;
    } while (n != 0);
    return sum;
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test n\n");
        exit(-1);
    }

    printf("%s\n", isHappy(atoi(argv[1])) ? "true" : "false");
    return 0;
}
