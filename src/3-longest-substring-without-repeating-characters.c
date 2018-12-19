#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char* s);

int main() {
    char *s = "abcabcbb";
    int max = lengthOfLongestSubstring(s);
    printf("%d\n",max);
}

//sliding window, can optimize better.
int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    int max = 1;
    for (int i = 0; i < length - 1; i++) {
        int freq[255] = {0};
        freq[s[i]] += 1;
        for (int j = i+1; j < length; j++) {
            if (freq[s[j]] > 0) {
                break;
            } else {
                max = ((max < j-i+1) ? j-i+1 : max);
                freq[s[j]]++;
            }
        }
    }
    return max;
}

//optimized sliding window, by speeding up shifting i.
int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    int max = 1;
    for (int i = 0; i < length - 1; i++) {
        int freq[255];
        memset(freq, 0xff, sizeof(freq));
        freq[s[i]] = i;
        for (int j = i+1; j < length; j++) {
            if (freq[s[j]] != -1) {
                i = freq[s[j]];
                break;
            } else {
                max = ((max < j-i+1) ? j-i+1 : max);
                freq[s[j]] = j;
            }
        }
    }
    return max;
}

// bruteforce version, timeout for very long testcase.
bool allUnique(char *s, int start, int end) {
    int ch[255] = {0};
    for (int i = start; i <= end; i++) {
        if (ch[s[i]] == 0) {
            ch[s[i]]++;
        } else {
            return false;
        }
    }
    return true;
}

int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (length == 0) {
        return 0;
    }
    int max = 1;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (j - i + 1 > max) {
                if (allUnique(s, i, j)) {
                    max = j - i + 1;
                }
            }
        }
    }
    return max;
}
