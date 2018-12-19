#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * for algorithm-wise, please check https://www.weibo.com/ttarticle/p/show?id=2309403998506351243972
 * for efficiency-wise, can be optimized. and WILL BE optimized.
 */
char* multiply(char* num1, char* num2, int *offset) {
    int num1Length = strlen(num1);
    int num2Length = strlen(num2);
    int resultLength = num1Length + num2Length;
    char *result = calloc(resultLength + 1, sizeof(char));
    result[resultLength] = '\0';
    reverse(num1);
    reverse(num2);
    int carry = 0;
    int sum = 0;
    int digit;
    for(int i = 0; i < resultLength; i++) {
        for (int j = 0; j < num1Length; j++) {
            for (int k = 0; k < num2Length; k++) {
                if (j + k == i) {
                    sum += (num1[j] - '0') * (num2[k] - '0');
                }
            }
        }
        sum += carry;
        digit = sum % 10;
        result[i] = digit + '0';
        carry = sum / 10;
        sum = 0;
    }
    reverse(result);
    while (*offset < resultLength - 1) {
        if (result[*offset] != '0') {
            break;
        }
        (*offset)++;
    }
    return result + *offset;
}

void reverse(char *num) {
    int length = strlen(num);
    int left = 0;
    int right = length - 1;
    while (left < right) {
        char tmp = num[left];
        num[left] = num[right];
        num[right] = tmp;
        left++;
        right--;
    }
}

int main() {
    char num1[] = "321";
    char num2[] = "123";
    int offset = 0;
    char *result = multiply(num1, num2, &offset);
    printf("%s\n", result);
    free(result - offset);
}
