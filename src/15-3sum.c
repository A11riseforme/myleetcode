#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp(const void* elem1, const void* elem2) {
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    return (f > s) - (f < s);
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
// too slow, to be revised
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if (numsSize < 3) {
        return NULL;
    }
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int **result = malloc(100000 * sizeof(int*));
    *returnSize = 0;
    int mid, l, r, left, right, target, leftValue, rightValue;
    for (l = 0; l < numsSize - 2 && nums[l] <= 0; ++l) {
        while (l > 0 && l < numsSize - 1 && nums[l] == nums[l - 1]) {
            ++l;
        }
        for (r = numsSize - 1; r > l + 1 && nums[r] >= 0; --r) {
            while (r < numsSize - 1 && r > 1 && nums[r] == nums[r + 1]) {
                --r;
            }
            target = -nums[l] - nums[r];
            int left = l + 1;
            int right = r - 1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[mid] == target) {
                    if (*returnSize == 0 || result[*returnSize - 1][0] != nums[l] || result[*returnSize - 1][1] != nums[mid] || result[*returnSize - 1][2] != nums[r]) {
                        result[*returnSize] = malloc(3 * sizeof(int));
                        result[*returnSize][0] = nums[l];
                        result[*returnSize][1] = nums[mid];
                        result[(*returnSize)++][2] = nums[r];
                        break;
                    } else {
                        break;
                    }
                } else if (nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
    }
    return result;
}


int main(int argc, char **argv) {
    /*
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }
    */
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int returnSize;
    int **result = threeSum(nums, sizeof(nums) / sizeof(nums[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d %d %d\n", result[i][0], result[i][1], result[i][2]);
        free(result[i]);
    }
    free(result);
}
