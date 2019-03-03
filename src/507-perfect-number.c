#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool checkPerfectNumber(int num) {
    if (num == 1) {
        return false;
    }
    int sum = 1;
    for (int i = 2; i < sqrt(num); ++i) {
        if (num % i) {
            continue;
        }
        sum += i;
        if (i * i != num) {
            sum += num / i;
        }
    }
    return sum == num;
}


int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number...\n");
        exit(-1);
    }

    printf("%s\n", checkPerfectNumber(atoi(argv[1])) ? "yes" : "no");
    return 0;
}
