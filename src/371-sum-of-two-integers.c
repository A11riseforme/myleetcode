#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int getSum(int a, int b) {
    if (b == 0) {
        return a;
    }
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
}


int main(int argc, char** argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number1 number2 \n");
        exit(-1);
    }
    printf("%d", getSum(atoi(argv[1]),atoi(argv[2])));
    return 0;
}
