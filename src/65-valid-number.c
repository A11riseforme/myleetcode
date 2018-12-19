#include <stdio.h>
#include <stdbool.h>

bool isNumber(char *s) {
    // skip all the spaces from the start
    while (*s == ' ') {
        s++;
    }
    bool if_find_num = false;
    // -/+ can only exist as the first non-space char, skip it.
    if (*s == '-' || *s == '+') {
        s++;
    }
    while (isdigit(*s)) {
        if_find_num = true;
        s++;
    }
    // . can only exist once before e, skip it.
    if (*s == '.') {
        ++s;
    }
    while (isdigit(*s)) {
        if_find_num = true;
        ++s;
    }
    if (if_find_num == true && *s == 'e') {
        s++;
        // only one -/+ followed by pure digits can exist after e
        if (*s == '+' || *s == '-') {
            s++;
        }
        if_find_num = false;
        while (isdigit(*s)) {
            if_find_num = true;
            s++;
        }
    }
    // skip all the spaces from the end.
    while (*s == ' ') {
        ++s;
    }
    return *s == '\0' && if_find_num == true;
}


int main() {
    int *s = "53.5e93";
    if (isNumber(s)) {
        printf("%s is number", s);
    } else {
        printf("%s is not number", s);
    }
}