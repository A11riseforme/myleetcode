#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>


int thirdMax(int* nums, int numsSize) {
    int one = INT_MIN, two = INT_MIN, three = INT_MIN;
    bool flag = false;
    for (int i = 0; i < numsSize; ++i) {
        one = nums[i] > one ? nums[i] : one;
    }
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != one)
            two = nums[i] > two ? nums[i] : two;
    }
    for(int i = 0; i < numsSize; ++i) {
        if(nums[i] != one && nums[i] != two) {
            three = nums[i] > three ? nums[i] : three;
            flag = true;
        }
    }
    return flag ? three : one;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number \n");
        exit(-1);
    }
    */
    int nums[] = {1, 2, 2, 9, 3, 2, 1, 5, 8};
    printf("%d", thirdMax(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
