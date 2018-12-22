#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// all the long type is to prevent overflow for edge cases like "-2147483648"
char* fractionToDecimal(int numerator, int denominator) {
    long remainders[1024] = {0};
    long decimals[1024] = {0};
    bool isRecurring = false;
    bool isNegative = false;
    if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
        isNegative = true;
    }
    char *result = calloc(1024, sizeof(char));
    long NewNumerator = labs(numerator);
    long NewDenominator = labs(denominator);
    int i = 0;
    int j = 0;
    if (isNegative) {
        result[0] = '-';
        j++;
    }
    int start = 0;
    long integer = NewNumerator / NewDenominator;
    long remainder = NewNumerator % NewDenominator;
    char integers[1024];
    sprintf(integers, "%ld", integer);
    strncpy(result + j, integers, strlen(integers));
    j += strlen(integers);
    if (remainder == 0) {
        return result;
    }
    result[j++] = '.';
    for (; ; i++) {
        remainders[i] = remainder;
        decimals[i] = (10 * remainder) / NewDenominator;
        if (remainder == 0) {
            isRecurring = false;
            break;
        }
        remainder = (10 * remainder) % NewDenominator;
        if (!isRecurring) {
            for (int k = 0; k <= i; k++) {
                if (remainder == remainders[k]) {
                    isRecurring = true;
                    start = k;
                    break;
                }
            }
            if (isRecurring) {
                break;
            }
        }
    }
    if (!isRecurring) {
        for (int k = 0; k < i;) {
            result[j++] = decimals[k++] + '0';
        }
        return result;
    }
    for (int k = 0; k < start;) {
        result[j++] = decimals[k++] + '0';
    }
    result[j++] = '(';
    for (int k = start; k <= i;) {
        result[j++] = decimals[k++] + '0';
    }
    result[j] = ')';
    return result;
}


int main(int argc, char** argv) {
#if 1
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test numerator denominator\n");
        exit(-1);
    }

    printf("%s\n", fractionToDecimal(atoi(argv[1]), atoi(argv[2])));
#else
    printf("%s\n", fractionToDecimal(1, 6));
    printf("%s\n", fractionToDecimal(100, 6));
    printf("%s\n", fractionToDecimal(-1, 4));
    printf("%s\n", fractionToDecimal(1, -3));
    printf("%s\n", fractionToDecimal(-1, -6));
    printf("%s\n", fractionToDecimal(25, 99));
    printf("%s\n", fractionToDecimal(1, 7));
    printf("%s\n", fractionToDecimal(10, 7));
    printf("%s\n", fractionToDecimal(100, 7));
    printf("%s\n", fractionToDecimal(1, 17));
    printf("%s\n", fractionToDecimal(1, 1024));
    printf("%s\n", fractionToDecimal(-2147483648, -1999));
    printf("%s\n", fractionToDecimal(-1, -2147483648));
#endif
    return 0;
}
