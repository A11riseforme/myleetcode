#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *result = calloc(digitsSize + 1, sizeof(int));
    int carry = 1, sum, digit;
    *(result + digitsSize) = digit;
    for (int i = digitsSize - 1; i >= 0; i--) {
        sum = digits[i] + carry;
        digit = sum % 10;
        carry = sum / 10;
        *(result + i + 1) = digit;
    }
    if (carry == 1) {
        *returnSize = digitsSize + 1;
        *result = 1;
    } else {
        for (int i = 0; i < digitsSize; i++) {
            *(result + i) = *(result + i + 1);
        }
        *returnSize = digitsSize;
    }
    return result;
}


int main() {
    int digits[3] = {9, 9, 9};
    int returnSize;
    int *result = plusOne(digits, 3, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", *(result + i));
    }
    free(result);
}
