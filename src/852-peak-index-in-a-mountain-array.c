#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int peakIndexInMountainArray(int* A, int ASize) {
    for (int i = 1; i < ASize - 1; ++i) {
        if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            return i;
        }
    }
    return 0;
}


int main(int argc, char** argv) {
    int nums[] = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    printf("%d", peakIndexInMountainArray(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
