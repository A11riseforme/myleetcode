#include <stdio.h>

// to do: implement with KMP and Boyer-Moore algorithm.

int strStr(char* haystack, char* needle) {
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if (len2 == 0) {
        return 0;
    }
    if (len1 < len2) {
        return -1;
    }
    int res = 1;
    for (int i = 0; i < len1 - len2 + 1; i += 1) {
        if (haystack[i] == needle[0]) {
            for (int j = 0; j < len2; j += 1) {
                if (haystack[i + j] != needle[j]) {
                    res *= 0;
                }
            }
            if (res == 1) {
                return i;
            }
        }
        res = 1;
    }
    return -1;
}


int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    int pos = strStr(haystack,needle);
    printf("%d",pos);
}
