#include <stdio.h>
#include <stdlib.h>

int *twoSum(int numbers[], int n, int target) {
    int index1;
    int index2;
    int* ret = (int*)malloc(sizeof(int) * 2);
    for (index1 = 0; index1 < n; index1++) {
        for (index2 = index1 + 1; index2 < n; index2++) {
            int sum_tmp = numbers[index1] + numbers[index2];
            if (sum_tmp == target) {
                ret[0] = index1;
                ret[1] = index2;
                return ret;
            }
        }
    }
    return NULL;
}

int main() {
    int nums[] = { 3, 2, 3 };
    int count = sizeof(nums) / sizeof(*nums);
    int target = 6;
    int *indexes = twoSum(nums, count, target);
    if (indexes != NULL) {
        printf("%d %d\n", indexes[0], indexes[1]);
    } else {
        printf("Not found\n");
    }

    free(indexes);

    return 0;
}

