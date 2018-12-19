#include <stdio.h>
#include <stdbool.h>

bool isValid(char* s) {
    char stack[1000000];
    int top = -1;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == ')') {
            if (top >= 0 && stack[top] == '(')
                top--;
            else
                return false;
        } else if (s[i] == ']') {
            if (top >= 0 && stack[top] == '[')
                top--;
            else
                return false;
        } else if (s[i] == '}') {
            if (top >= 0 && stack[top] == '{')
                top--;
            else
                return false;
        } else {
            top++;
            stack[top] = s[i];
        }
    }
    return top == -1;
}

int main() {
    char input[] = "(){}[]";
    printf("%s\n", isValid(input) ? "valid" : "invalid");
}
