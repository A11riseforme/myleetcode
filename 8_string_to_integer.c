#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int myAtoi(char* str) {
    char *a;
    int n = 0;
    bool positive = true;
    int flag = 0;
    while (*str == ' ') {
        str++;
    }
    for (a = str; *a != '\0'; a++) {
        if (isdigit(*a)) {
            flag = 1;
            if (positive) {
                if (n > (INT_MAX - (*a - '0')) / 10) {
                    return INT_MAX;
                }
            } else {
                if (-n < (INT_MIN + (*a - '0')) / 10) {
                    return INT_MIN;
                }
            }
            n = n * 10 + (*a - '0');
        } else if ((*a == '-' || *a == '+') && isdigit(*(a + 1)) && flag == 0) {
            positive = (*a == '+');
        } else {
            break;
        }
    }
    return n * (positive ? 1 : -1);
}


int main() {
    char *s = "    123";
    int  a = myAtoi(s);
    printf("%d", a);
}



