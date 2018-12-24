#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum3(int k, int n, int** columnSizes, int* returnSize) {
    int minSum = (k+1)*k/2;
    int maxSum = (19-k)*k/2;
    if (k > 9 || n < minSum || n > maxSum) {
        return NULL;
    }
    int **result = malloc(20 * sizeof(int *));
    int nums[k];
    *returnSize = 0;
    helper(k, n, 0, 0, nums, result, returnSize);
    *columnSizes = malloc((*returnSize) * sizeof(int *));
    for (int i = 0; i < *returnSize; i++) {
        (*columnSizes)[i] = k;
    }
    return result;
}

void helper(int k, int n, int index, int sum, int *nums, int **result, int *count) {
    if (sum > n) {
        return;
    }
    if (index == k) {
        if (sum == n) {
            result[*count] = malloc(k * sizeof(int));
            memcpy(result[(*count)++], nums, k * sizeof(int));
            return;
        }
        return;
    }
    else {
        for (int i = index > 0 ? nums[index-1]+1 : 1; i < 10 && sum + i <= n; i++) {
            nums[index] = i;
            helper(k, n, index+1, sum + i, nums, result, count);
        }
    }
}


int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./test k n\n");
        exit(-1);
    }

    int k = atoi(argv[1]);
    int n = atoi(argv[2]);
    int *sizes, count = 0;
    int **lists = combinationSum3(k, n, &sizes, &count);
    for (int i = 0; i < count; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            printf("%d ", lists[i][j]);
        }
        printf("\n");
    }
    free(sizes);
    for (int i = 0; i < count; i++) {
        free(lists[i]);
    }
    free(lists);
    return 0;
}
