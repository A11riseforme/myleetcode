#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int i = 0;
    int j = numbersSize - 1;
    int *a = calloc(2, sizeof(int));
    while(i < j) {
        if(numbers[i] + numbers[j] == target) {
            a[0] = i + 1;
            a[1] = j + 1;
            break;
        }
        if(numbers[i] + numbers[j] > target) {
            j--;
        }
        if(numbers[i] + numbers[j] < target) {
            i++;
        }
    }
    *returnSize = 2;
    return a;
}


int main(int argc, char **argv) {
    int nums[5] = {2,7,11,15,17};
    int returnSize;
    int *result = twoSum(nums, 5, 18, &returnSize);
    printf("%d, %d", result[0], result[1]);
    free(result);
}
