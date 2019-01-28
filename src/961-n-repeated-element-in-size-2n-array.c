#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int repeatedNTimes(int* A, int ASize) {
    for (int i = 0; i < ASize - 2; ++i) {
        if (A[i] == A[i + 1] || A[i] == A[i + 2]) {
            return A[i];
        }
    }
    return A[ASize - 1];
}


int main(int argc, char** argv) {
    int nums[] = {5, 1, 5, 2, 5, 3, 5, 4};
    printf("%d", repeatedNTimes(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
