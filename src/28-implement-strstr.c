#include <stdio.h>

// to do: implement with Boyer-Moore algorithm.

// brute force.
int strStrSlow(char* haystack, char* needle) {
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


void generateNext(char* p, int next[]) {
    int pLen = strlen(p);
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
        if (k == -1 || p[j] == p[k]) {
            j++;
            k++;
            if (p[j] != p[k]) {
                next[j] = k;
            } else {
                next[j] = next[k];
            }
        } else {
            k = next[k];
        }
    }
}

// KMP algorithm.
int strStrKMP(char* haystack, char* needle) {
    int i = 0;
	int j = 0;
	int hLen = strlen(haystack);
	int nLen = strlen(needle);
    if (nLen == 0) {
        return 0;
    }
    if (hLen < nLen) {
        return -1;
    }
    int next[nLen];
    generateNext(needle, next);
	while (i < hLen && j < nLen) {
		if (j == -1 || haystack[i] == needle[j]) {
			i++;
			j++;
		} else {
			j = next[j];
		}
	}
	if (j == nLen) {
		return i - j;
    } else {
		return -1;
    }
}


int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    int pos = strStrKMP(haystack,needle);
    printf("%d",pos);
}
