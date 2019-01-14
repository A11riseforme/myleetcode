#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool checkPossibility(int* nums, int numsSize) {
    int count = 0;
    for (int i = 1; i < numsSize; ++i) {
        // if decrease happens.
        if (nums[i] < nums[i - 1]) {
            if (count == 1) {
                return false;
            }
            // deal with {4，2，3} or {0，4，2，3}
            if (i == 1 || nums[i] >= nums[i - 2]) {
                nums[i - 1] = nums[i];
            }
            // deal with {5,4,6}
            else {
                nums[i] = nums[i - 1];
            }
            ++count;
        }
    }
    return true;
}


int main() {
    int nums[] = {1, 2, 2, 3, 6, 5};
    printf("%s\n", checkPossibility(nums, 6) ? "possible" : "impossible");
    return 0;
}
