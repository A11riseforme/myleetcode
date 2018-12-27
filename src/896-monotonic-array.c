#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMonotonic(int* A, int ASize) {
    bool increasing = true;
    bool decreasing = true;
    for (int i = 0; i < ASize-1; i++) {
        increasing = increasing ? A[i] <= A[i+1] : increasing;
        decreasing = decreasing ? A[i] >= A[i+1] : decreasing;
    }
    return increasing || decreasing;
}

int main() {
    int nums[] = {1,2,4,5,7,3};
    printf("nums are %smonotonic\n", isMonotonic(nums, 6) ? "" : "not ");
}
