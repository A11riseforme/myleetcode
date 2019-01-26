#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int numFriendRequests(int* ages, int agesSize) {
    int count[121] = {0};
    for (int i = 0; i < agesSize; ++i) {
        ++count[ages[i]];
    }
    int result = 0;
    for (int A = 1; A <= 120; ++A) {
        for (int B = 0.5 * A + 8; B <= A; ++B) {
            // n people of the same age, total n*(n-1) friend requests can be made.
            result += count[A] * (count[B] - (A == B));
        }
    }
    return result;
}

int main() {
    int ages[] = {20, 30, 100, 110, 120};
    printf("%d", numFriendRequests(ages, 5));
    return 0;
}
