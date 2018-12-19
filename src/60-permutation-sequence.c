#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// check is number is permutation of 1 to n.
bool isPermutation(int number, int n) {
    int freq[10] = {0};
    int digit;
    for (int i = 0; i < n; i++) {
        digit = number % 10;
        if (freq[digit] != 0) {
            return false;
        }
        freq[digit]++;
        number /= 10;
    }
    return true;
}


int numProduct(int n) {
    if (n == 0) {
        return 0;
    }
    int result = 1;
    while (n > 0) {
        result *= n%10;
        n /= 10;
    }
    return result;
}

//Time Limit Exceeded, f**king slow, but work, code just for fun.
char* getPermutationSlow(int n, int k) {
    // product the the product of digits in permutation.
    int product = 1;
    for (int i = 1; i <= n; i++) {
        product *= i;
    }
    // initial is the first permutation. 1234***n
    int initial = 0;
    for (int i = 1; i <= n; i++) {
        initial = initial * 10 + i;
    }
    int count = 0;
    int target;
    for (target = initial - 1; count < k; target++) {
        if (isPermutation(target, n)) {
            if (numProduct(target) == product) {
                count++;
            }
        }
    }
    target--;
    char *result = calloc(n+1, sizeof(char));
    for (int i = n-1; i >= 0; i--) {
        result[i] = target%10 + '0';
        target /= 10;
    }
    return result;
}


char* getPermutation(int n, int k) {
    int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int fact[9] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    char *result = calloc(n+1, sizeof(char));
    if (n == 1) {
        *result = getLastNumber(digits, n) + '0';
        return result;
    }
    int digit, index, i;
    for (i = 0; i < n-1; i++) {
        index = (k-1) / fact[n - i - 2];
        k %= fact[n - i - 2];
        digit = getNumber(digits, index);
        *(result + i) = digit + '0';
        if (k == 0) {
            break;
        }
    }
    for (int j = i+1; j < n; j++) {
        *(result + j) = getLastNumber(digits, n) + '0';
    }
    return result;
}

int getNumber(int *digits, int order) {
    int i;
    for (i = 0; order >= 0; i++) {
        if (digits[i] != 0) {
            order--;
        }
    }
    int tmp = digits[i-1];
    digits[i-1] = 0;
    return tmp;
}

int getLastNumber(int *digits, int n) {
    for (int i = n -1; i >= 0; i--) {
        if (digits[i] != 0) {
            int tmp = digits[i];
            digits[i] = 0;
            return tmp;
        }
    }
    return 0;
}


int main() {
    char *result = getPermutation(9, 12345);
    printf("%s",result);
    free(result);
}
