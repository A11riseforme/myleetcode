#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int len = strlen(s);
    int length = 0;
    if (len == 0) {
        return 0;
    }
    int i = len - 1;
    while (i >= 0) {
        if (*(s+i) != ' ') {
            length += 1;
        } else if (*(s+i) == ' ' && length != 0){
            break;
        }
        i -= 1;
    }
    return length;
}


int main() {
    int *s = "hello world";
    printf("last word's length is %d", lengthOfLastWord(s));
}
