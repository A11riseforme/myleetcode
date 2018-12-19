#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int cmp (const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    int min = nums[0];
    int max = nums[numsSize - 1];
    int range = max - min;
    int *freq = calloc(range + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] - min]++;
    }
    int maxSize = 1;
    int n = numsSize;
    while (n > 0) {
        maxSize *= n;
        n--;
    }
    for (int i = 0; i <= range; i++) {
        if (freq[i] > 1) {
            for (int j = freq[i]; j > 1; j--) {
                maxSize /= j;
            }
        }
    }
    *returnSize = maxSize;
    int **result = calloc(*returnSize, sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        *(result + i) = calloc(numsSize, sizeof(int));
    }

    int *initial = calloc(numsSize, sizeof(int));
    memcpy(initial, nums, numsSize * sizeof(int));
    for (int i = 0; i < *returnSize; i++) {
        memcpy(*(result + i), initial, numsSize * sizeof(int));
        nextPermutation(initial, numsSize);
    }
    free(initial);
    free(freq);

    return result;
}


void reverse(int *nums, int left, int right) {
    while (left < right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        left++;
        right--;
    }
}


void nextPermutation(int* nums, int numsSize) {
    int swap_1_position = -1;
    int swap_2_position = -1;
    if (numsSize == 1) {
        return;
    }
    // start from the right, we look for the first number which is less than its right. this is the first swapping position.
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            swap_1_position = i - 1;
            // look for the smallest number on the first swap position's right which is greater than the value on the first swapping position.
            for (int l = numsSize - 1; l >= swap_1_position; l--) {
                if (nums[l] > nums[swap_1_position]) {
                    swap_2_position = l;
                    break;
                }
            }
            break;
        }
    }
    // if swap_1_position is not found, the original nums is biggest, just reverse it.
    if (swap_1_position == -1) {
        reverse(nums, 0, numsSize - 1);
        return;
    }
    // swap the number on two swapping positions.
    int temp = nums[swap_1_position];
    nums[swap_1_position] = nums[swap_2_position];
    nums[swap_2_position] = temp;

    // reverse the numbers on the right of the first swapping position.
    reverse(nums, swap_1_position + 1, numsSize - 1);
    return;
}


int main() {
    int nums[] = {1, 2, 2, 3, 3};
    int returnSize;
    int **result = permuteUnique(nums, 5, &returnSize);
    printf("returnSize is %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < returnSize; i++) {
        free(*(result + i));
    }
    free(result);
}
