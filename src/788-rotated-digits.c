#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int rotatedDigits(int N) {
    int convert[10] = {0,1,5,3,4,2,9,7,8,6};
    int k, ref, tmp, lastDigit, result = 0;
    bool good;
    for (int i = 1; i <= N; ++i) {
        good = true;
        tmp = 0;
        k = 0;
        ref = i;
        while (ref > 0) {
            lastDigit = ref % 10;
            if (lastDigit == 3 || lastDigit == 4 || lastDigit == 7) {
                good = false;
                break;
            }
            tmp += convert[lastDigit] * pow(10, k++);
            ref /= 10;
        }
        if (good && tmp != i) {
            ++result;
        }
    }
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    printf("%d", rotatedDigits(atoi(argv[1])));
    return 0;
}
