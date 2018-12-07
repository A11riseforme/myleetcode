#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x == 0) {
        return true;
    }
    if (x < 0) {
        return false;
    }
    int reversed_num = reverse(x);
    if (x == reversed_num) {
        return true;
    }
    return false;
}

int reverse(int x) {
    int new_number = 0;
    while (x != 0){
        int d = x % 10;
        new_number = new_number * 10 + d;
        x /= 10;
    }
    return new_number;
}

int main() {
    printf("%s\n", isPalindrome(12321) ? "true" : "false");
return 0;
}
