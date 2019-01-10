#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool find132pattern(int* nums, int numsSize) {
    if (numsSize < 3) {
        return false;
    }
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < numsSize) {
        // look for the bottom.
        while (i < numsSize - 2 && nums[i] >= nums[i + 1]) {
            i++;
        }
        // look for the top.
        j = i + 1;
        while (j < numsSize - 1 && nums[j] <= nums[j + 1]) {
            j++;
        }
        // look for a number after j which is betwen nums[i] and nums[j].
        k = j + 1;
        while (k < numsSize) {
            if (nums[k] > nums[i] && nums[k] < nums[j]) {
                return true;
            }
            k++;
        }
        i = j + 1;
    }
    return false;
}

int main() {
    int nums[] = {3, 1, 4, 2};
    printf("%s", find132pattern(nums, 4) ? "yes" : "no");
    return 0;
}
