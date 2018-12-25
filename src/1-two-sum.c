#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} table;


int compare(const void *a, const void *b){
    return ((table *) a)->value - ((table *) b)->value;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 * counting sort, hash table.
 */
int *twoSum(int numbers[], int n, int target) {
    table *tables = malloc(n * sizeof(*tables));
    for (int i = 0; i < n; i++) {
        tables[i].value = numbers[i];
        tables[i].index = i;
    }
    qsort(tables, n, sizeof(*tables), compare);
    int left = 0;
    int right = n - 1;
    int diff;
    int *results = malloc(2 * sizeof(int));
    while (left < right) {
        int diff = target - tables[left].value;
        // if sum is too small -> left number is too small.
        if (diff > tables[right].value) {
            // move the left pointer to the right, until meet a left number with different bigger value.
            while (++left < right && tables[left].value == tables[left - 1].value) {}
        // if sum is too big -> right number is too big.
        } else if (diff < tables[right].value) {
            // move the right pointer to the left, until meet a right number with different smaller value.
            while (--right > left && tables[right].value == tables[right + 1].value) {}
        } else {
            results[0] = tables[left].index;
            results[1] = tables[right].index;
            free(tables);
            return results;
        }
    }
    free(results);
    free(tables);
    return NULL;
}


// brute force
int *twoSumSlow(int numbers[], int n, int target) {
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

