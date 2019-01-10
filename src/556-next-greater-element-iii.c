#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void reverse(int *nums, int left, int right) {
    while (left < right) {
        int temp = nums[left];
        nums[left++] = nums[right];
        nums[right--] = temp;
    }
}


// reuse the 31-next-permutation.c code.
int nextPermutation(int* nums, int numsSize) {
    int swap_1_position = -1;
    int swap_2_position = -1;
    if (numsSize == 1) {
        return -1;
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
    // if swap_1_position is not found, the original nums is biggest, return -1;
    if (swap_1_position == -1) {
        return -1;
    }
    // swap the number on two swapping positions.
    int temp = nums[swap_1_position];
    nums[swap_1_position] = nums[swap_2_position];
    nums[swap_2_position] = temp;

    // reverse the numbers on the right of the first swapping position.
    reverse(nums, swap_1_position + 1, numsSize - 1);
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        // if overflow, return -1
        if (result > INT_MAX / 10) {
            return -1;
        }
        result = result * 10 + nums[i];
    }
    return result;
}


int nextGreaterElement(int n) {
    int *arr = malloc(10 * sizeof(int));
    int len = 0;
    while(n) {
        arr[len++] = n % 10;
        n /= 10;
    }
    reverse(arr, 0, len - 1);
    int result = nextPermutation(arr, len);
    free(arr);
    return result;
}


int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("%d", nextGreaterElement(atoi(argv[1])));
    return 0;
}
