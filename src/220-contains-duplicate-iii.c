#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// paste from 219-contains-duplicate-ii.c
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


// won't be able to handle extreme test cases containing INT_MAX, INT_MIN
// to be improved.
bool containsNearbyAlmostDuplicate(int* nums, int numsSize, int k, int t) {
    if(numsSize == 1) {
        return false;
    }
    if (t == 0) {
        // t = 0, it is just qn 219.
        return containsNearbyDuplicate(nums, numsSize, k);
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
        for (int j = ((nums[i]-min-t < 0) ? 0 : (nums[i]-min-t)); j <= ((nums[i]-min+t > max - min) ? max - min : (nums[i]-min+t)); j++) {
            if (tables[j] != -1 && i - tables[j] <= k) {
                free(tables);
                return true;
            }
        }
    tables[nums[i] - min] = i;
    }
    free(tables);
    return false;
}


int main() {
    int nums[] = {1,5,9,1,5,9};
    int k = 2;
    int t = 3;
    printf("%s", containsNearbyAlmostDuplicate(nums, 6, k, t) ? "yes" : "no");
}
