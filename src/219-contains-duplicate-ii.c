#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// can be optimized using hash table or sliding window.
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
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
