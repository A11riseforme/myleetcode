#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define MAX(a,b) ((a)>(b)) ? (a) : (b)

char* addStrings(char* num1, char* num2, bool *leadZero) {
    int num1Len = strlen(num1);
    int num2Len = strlen(num2);
    int max = MAX(num1Len, num2Len);
    char *result = malloc((max + 2) * sizeof(char));
    result[max + 1] = '\0';
    long i = num1Len - 1;
    long j = num2Len - 1;
    long diff = abs(num1Len - num2Len);

    long sum = 0;
    long tenth = 0;
    while (i >= 0 && j >= 0) {
        sum = ((num1[i] - '0') + (num2[j] - '0') + tenth) % 10 ;
        tenth =  ((num1[i--] - '0') + (num2[j--] - '0') + tenth) / 10;
        result[max--] = sum + '0';
    }
    if (num1Len > num2Len) {
        for (long i = diff - 1; i >= 0; --i) {
            sum = ((num1[i] - '0') + tenth) % 10 ;
            tenth = ((num1[i] - '0') + tenth) / 10 ;
            result[i + 1] = sum + '0';
        }
        result[0] = tenth + '0';
    } else {
        for (long i = diff - 1; i >= 0; --i) {
            sum = ((num2[i] - '0') + tenth) % 10 ;
            tenth = ((num2[i] - '0') + tenth) / 10 ;
            result[i + 1] = sum + '0';
        }
        result[0] = tenth + '0';
    }
    if (result[0] == '0') {
        *leadZero = true;
        return result + 1;
    }
    return result;
}


int main(int argc, char **argv) {

    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number1 number2...\n");
        exit(-1);
    }

    bool leadZero = false;
    char *result = addStrings(argv[1], argv[2], &leadZero);
    printf("%s\n", result);
    if (leadZero) {
        free(--result);
    } else {
        free(result);
    }
    return 0;
}
