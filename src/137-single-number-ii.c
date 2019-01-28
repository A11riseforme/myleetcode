#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int singleNumber(int* nums, int numsSize) {
    int bit, count, result = 0;
    for (int i = 0; i < 32; ++i) {
        count = 0;
        bit = 1 << i;
        for (int j = 0; j < numsSize; ++j) {
            if (nums[j]&bit) {
                ++count;
            }
        }
        if (count % 3) {
            result |= bit;
        }
    }
    return result;
}

int main() {
    int nums[] = {0, 1, 0, 1, 0, 1, 99};
    printf("%d\n", singleNumber(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
