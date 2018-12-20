#include <stdio.h>
#include <stdlib.h>

int maxProduct(int* nums, int numsSize) {
    int globalMax = nums[0];
    int localMax = nums[0];
    int localMin = nums[0];
    for (int i = 1; i < numsSize; i++) {
        int tmpMax = localMax;
        localMax = max(localMax * nums[i], localMin * nums[i], nums[i]);
        localMin = min(tmpMax * nums[i], localMin * nums[i], nums[i]);
        globalMax = globalMax > localMax ? globalMax : localMax;
    }
    return globalMax;
}

int max(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    if (b >= a && b >= c) {
        return b;
    }
    return c;
}

int min(int a, int b, int c) {
    if (a <= b && a <= c) {
        return a;
    }
    if (b <= a && b <= c) {
        return b;
    }
    return c;
}


int main(int argc, char **argv) {
    int i, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%d\n", maxProduct(nums, count));
    free(nums);
    return 0;
}
