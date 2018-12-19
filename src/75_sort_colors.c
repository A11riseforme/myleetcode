#include <stdio.h>

// place all the met red balls to the left,
// and all the met blue balls to the right.
// then what is left in the middle is white balls.
void sortColors(int* nums, int numsSize) {
    int redPos = 0;
    int bluePos = numsSize - 1;
    for (int i = 0; i <= bluePos; i++) {
        if (nums[i] == 0) {
            swap(nums, redPos, i);
            redPos++;
        } else if (nums[i] == 2) {
            swap(nums, bluePos, i);
            bluePos--;
            // you don't know what number did you
            // swap here, maybe 0/2? so need to check again.
            // therefore, i--
            i--;
        }
    }
}


void swap(int *nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
}


int main() {
    int colors[] = {2,0,2,1,1,0};
    sortColors(colors, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d ",colors[i]);
    }
}
