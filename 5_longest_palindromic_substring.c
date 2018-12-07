#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int expandAroundCenter(char *s, float center) {
    int totalLength = strlen(s);
    int left = (center - (int)center > 0.1 ? (int)center : (int)center-1);
    int right = (int)center+1;
    int length = right - left - 1;
    while (left >= 0 && right < totalLength && *(s+left) == *(s+right)) {
        length += 2;
        left--;
        right++;
    }
    return length;
}

char* longestPalindrome(char *s) {
    int length = strlen(s);
    float center = 0.0;
    int maxLength = 1;
    for (float i = 0.5; i < length-1; i += 0.5) {
        int tmpLength = expandAroundCenter(s, i);
        if (tmpLength > maxLength) {
            center = i;
            maxLength = tmpLength;
        }
    }
    char *palindrome = calloc(maxLength+1, sizeof(char));
    int left = (center - (int)center > 0.1 ? (int)center+1 - maxLength/2 : (int)center - maxLength/2);
    int right = left + maxLength - 1;
    int i = 0;
    for (int i = 0; left <=right; i++) {
        *(palindrome + i) = *(s + left);
        left++;
    }
    *(palindrome + maxLength) = '\0';
    return palindrome;
}

int main() {
    char *s = "babad";
    char *a = longestPalindrome(s);
    printf("%s",a);
    free(a);
}
