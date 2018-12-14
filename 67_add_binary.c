#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b, int *offset) {
    int aLength = strlen(a);
    int bLength = strlen(b);
    int diff = labs(aLength - bLength);
    int max = (aLength > bLength) ? aLength : bLength;
    char *result = calloc(max + 2, sizeof(char));
    result[max + 1] = '\0';
    int carry = 0;
    int tmp;
    int i;
    int j;
    for (i = aLength - 1, j = bLength - 1; i >= 0 && j >= 0; i--, j--, max--) {
        tmp = ((a[i] - '0') + (b[j] - '0') + carry) % 2;
        carry = ((a[i] - '0') + (b[j] - '0') + carry) / 2;
        result[max] = tmp + '0';
    }
    if (aLength > bLength) {
        for (int i = aLength - bLength - 1; i >= 0; i -= 1) {
            tmp = ((a[i] - '0') + carry) % 2 ;
            carry = ((a[i] - '0') + carry) / 2 ;
            result[i + 1] = tmp + '0';
        }
        result[0] = carry + '0';
    } else {
        for (int i = bLength - aLength - 1; i >= 0; i -= 1) {
            tmp = ((b[i] - '0') + carry) % 2 ;
            carry = ((b[i] - '0') + carry) / 2 ;
            result[i + 1] = tmp + '0';
        }
        result[0] = carry + '0';
    }
    if (result[0] == '0') {
        *offset = 1;
        return result + 1;
    }
    return result;
}


int main() {
    char *a = "10000";
    char *b = "1";
    int offset = 0;
    char *result = addBinary(a, b, &offset);
    printf("%s", result);
    free(result - offset);
}
