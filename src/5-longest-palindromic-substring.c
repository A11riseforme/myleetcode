#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MIN(a,b) ((a)<(b) ? (a) : b)

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

char* longestPalindromeSlow(char *s) {
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

// manacher algorithm. to be revised.
char* longestPalindrome(char* s) {
    char *str = malloc(2100*sizeof(char));
    int i, j = 0;
    // constructing ref string for manacher algorithm.
    str[j++] = '$';
    str[j++] = '#';
    for (i = 0; s[i] != '\0'; ++i) {
        str[j++] = s[i];
        str[j++] = '#';
    }
    str[j] = '\0'; // now j is the length of the ref string.
    int max_len = -1;  // longest palindrome length.

    int id;
    int center;// pos of the center of the longest palindrome.
    int mx = 0; // right pos of the longest palindrome.
    int p[2100];
    for (i = 1; i < j; i++) {
        if (i < mx) {
            p[i] = MIN(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (str[i - p[i]] == str[i + p[i]]) {
            p[i]++;
        }
        if (mx < i + p[i]) {
            id = i;
            mx = i + p[i];
        }
        if (p[i]-1 > max_len) {
            center = i;
            max_len = p[i]-1;
        }
    }
    int left = ceil((center-2.0)/2)-max_len/2;
    strncpy(str, s+left, max_len);
    str[max_len] = '\0';
    return str;
}


int main() {
    char *s = "babad";
    char *a = longestPalindrome(s);
    printf("%s",a);
    free(a);
}
