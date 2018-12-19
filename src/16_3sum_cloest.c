#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a , const void *b) {
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(*nums), cmp);
    int min_diff = INT_MAX;
    for (int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;
        while (left < right) {
            int sum = *(nums + left) + *(nums + i) + *(nums + right);
            int diff = sum - target;
            if (abs(diff) < abs(min_diff)) {
                min_diff = diff;
            }
            if (diff > 0) {
                right--;
            } else if (diff < 0) {
                left++;
            } else {
                break;
            }
        }
    }
    return target + min_diff;
}

int main() {
    int nums[4] = {-1, 2, 1, -4};
    int closestSum = threeSumClosest(nums, 4, 1);
    printf("%d", closestSum);
}
