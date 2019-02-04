#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

int cmp(const int* a, const int* b) {
    return *a > *b;
}


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(nums1[0]), cmp);
    qsort(nums2, nums2Size, sizeof(nums2[0]), cmp);
    int *result = malloc((nums1Size > nums2Size ? nums1Size : nums2Size) * sizeof(int));
    *returnSize = 0;
    for (int i = 0, j = 0; i < nums1Size && j < nums2Size;) {
        if (nums1[i] == nums2[j]) {
            result[(*returnSize)++] = nums1[i];
            ++i;
            ++j;
            continue;
        }
        if (nums1[i] < nums2[j]) {
            ++i;
            continue;
        }
        ++j;
    }
    return result;
}


int main(int argc, char** argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string \n");
        exit(-1);
    }
    */
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};
    int returnSize = 0;
    int *result = intersect(nums1, sizeof(nums1) / sizeof(nums1[0]), nums2, sizeof(nums2) / sizeof(nums2[0]), &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d\n", result[i]);
    }
    free(result);
    return 0;
}
