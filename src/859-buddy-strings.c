#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// slow version
bool buddyStringsSlow(char* A, char* B) {
    int aLen = strlen(A);
    int bLen = strlen(B);
    // A and B are not same length, obvious.
    if (aLen != bLen) {
        return false;
    }
    // if A and B are same, return true only if there are repeating alphabets.
    if (strcmp(A, B) == 0) {
        char freq[26] = {0};
        for (int i = 0; i < aLen; i++) {
            freq[A[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 1) {
                return true;
            }
        }
        return false;
    }
    // if A and B are not same, return true only if two pairs of different alphabets.
    // that is A[i] == B[j] && B[i] == A[j]
    char a[aLen];
    char b[bLen];
    int pairs = 0;
    for (int i = 0; i < aLen; i++) {
        if (A[i] != B[i]) {
            a[pairs] = A[i];
            b[pairs++] = B[i];
        }
    }
    return pairs == 2 && a[0] == b[1] && a[1] == b[0];
}


// faster version, A == B can be handled by the algorithm of the third case.
bool buddyStrings(char* A, char* B) {
    int aLen = strlen(A);
    int bLen = strlen(B);
    // A and B are not same length, obvious.
    if (aLen != bLen) {
        return false;
    }
    // if A and B are same, return true only if there are repeating alphabets.
    // if A and B are not same, return true only if two pairs of different alphabets.
    // that is A[i] == B[j] && B[i] == A[j]
    char a[aLen + 1]; // handle both are empty strings case.
    char b[bLen + 1];
    int freq[26] = {0};
    int pairs = 0;
    for (int i = 0; i < aLen; i++) {
        freq[A[i] - 'a']++;
        if (A[i] != B[i]) {
            a[pairs] = A[i];
            b[pairs++] = B[i];
        }
    }
    if (pairs) {
        return pairs == 2 && a[0] == b[1] && a[1] == b[0];
    }
    // if not found different pairs, means they are the same.
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 1) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test string string\n");
        exit(-1);
    }
    printf("%s", buddyStrings(argv[1], argv[2]) ? "yes" : "no");
    return 0;
}
