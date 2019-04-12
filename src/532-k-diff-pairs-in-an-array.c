#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp(const int* a, const int *b) {
    return (*a - *b);
}

int findPairs(int* nums, int numsSize, int k) {
    if (k < 0 || numsSize < 2)
        return 0;
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    int last = nums[0] - 1;
    for(int i = 0; i < numsSize; i++) {
        if (last == nums[i]) {
            continue;
        }
        last = nums[i];
        for(int j = i + 1; j < numsSize; j++) {
            if(nums[i] + k == nums[j]) {
                ans++;
                break;
            } else if(nums[i] + k < nums[j]) {
                break;
            }
        }
    }
    return ans;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    int nums[] = {1, 2, 3, 4, 5};
    printf("%d\n", findPairs(nums, sizeof(nums) / sizeof(nums[0]), 1));
    return 0;
}

