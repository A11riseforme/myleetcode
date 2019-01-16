#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX(a, b) (a) > (b) ? (a) : (b)

// dp with memorization.
int choose(int* nums, int left, int right, int* mem, int numsSize) {
    if (left == right) {
        return nums[left];
    }
    int i = left * numsSize + right;
    if (mem[i] > 0) {
        return mem[i];
    }
    mem[i] = MAX(nums[left] - choose(nums, left + 1, right, mem, numsSize), nums[right] - choose(nums, left, right - 1, mem, numsSize));
    return mem[i];
}


bool PredictTheWinner(int* nums, int numsSize) {
    int *mem = calloc(numsSize * numsSize, sizeof(int));
    return choose(nums, 0, numsSize - 1, mem, numsSize) >= 0;
}


int main() {
    int nums[] = {10, 17, 11, 16, 17, 9, 14, 17, 18, 13, 11, 4, 17, 18, 15, 3, 13, 10, 6, 10};
    printf("%s", PredictTheWinner(nums, sizeof(nums) / sizeof(nums[0])) ? "yes" : "no");
    return 0;
}
