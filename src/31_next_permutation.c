#include <stdio.h>

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
        reverse(nums,0,numsSize-1);
        return;
    }
    // swap the number on two swapping positions.
    int temp = nums[swap_1_position];
    nums[swap_1_position] = nums[swap_2_position];
    nums[swap_2_position] = temp;

    // reverse the numbers on the right of the first swapping position.
    reverse(nums, swap_1_position+1,numsSize-1);
    return;
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


int main() {
    int nums[] = {2,3,4,6,5,7,0};
    nextPermutation(nums,7);
    for (int i = 0; i < 7; i++) {
        printf("%d ",nums[i]);
    }
}
