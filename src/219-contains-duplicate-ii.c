#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// can be optimized using hash table or sliding window.
bool containsNearbyDuplicateSlow(int* nums, int numsSize, int k) {
    if(numsSize == 1) {
        return false;
    }
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = i + 1; (j <= i + k) && (j < numsSize); j++) {
            if(nums[i] == nums[j])
                return true;
        }
    }
    return false;
}

// using counting sort.
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if(numsSize == 1) {
        return false;
    }
    int min = nums[0];
    int max = nums[0];
    for (int i = 0; i < numsSize; i++) {
        min = nums[i] < min ? nums[i] : min;
        max = nums[i] > max ? nums[i] : max;
    }
    int *tables = malloc((max - min + 1) * sizeof(int));
    for (int i = 0; i < max - min + 1; i++) {
        tables[i] = -1;
    }
    for (int i = 0; i < numsSize; i++) {
        // never appear before.
        if (tables[nums[i] - min] == -1) {
            tables[nums[i] - min] = i;
            continue;
        }
        if (tables[nums[i] - min] != -1) {
            // if interval is less than or equal to k.
            if (i - tables[nums[i] - min] <= k) {
                return true;
            }
            else {
                // record down last index of i.
                tables[nums[i] - min] = i;
            }
        }
    }
    return false;
}


int main(int argc, char **argv) {
    int i, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%s\n", containsNearbyDuplicate(nums, count, 3) ? "yes" : "no");
    free(nums);
    return 0;
}
