#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int comp (const void * a, const void * b) {
    return ( *(int*)a - * (int*)b );
}


bool containsDuplicate(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comp);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
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
    printf("%s\n", containsDuplicate(nums, count) ? "yes" : "no");
    free(nums);
    return 0;
}
