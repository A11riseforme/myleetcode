#include <stdio.h>
#include <limits.h>

int reverse(int x) {
    int new_number = 0;
    int not_negative = 1;
    if (x < 0) {
        not_negative = -1;
        x *= -1;
    }
    while (x != 0){
        int d = x % 10;
        if (new_number > INT_MAX / 10 || new_number < INT_MIN / 10) {
            return 0;
        }
        new_number = new_number * 10 + d;
        x /= 10;
    }
    return new_number * not_negative;
}

int main() {
    int test = 12344312;
    printf("%d",reverse(test));
}
