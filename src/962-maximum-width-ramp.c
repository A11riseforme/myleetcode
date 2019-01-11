#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int value;
    int index;
} table;

int compare(const void *a, const void *b) {
    return ((table *) a)->value - ((table *) b)->value;
}


int maxWidthRamp(int* A, int ASize) {
    table *tables = malloc(ASize * sizeof(table));
    for (int i = 0; i < ASize; i++) {
        tables[i].value = A[i];
        tables[i].index = i;
    }
    qsort(tables, ASize, sizeof(*tables), compare);
    int min = tables[0].index;
    int result = 0;
    for (int i = 1; i < ASize; i++) {
        result = result < tables[i].index - min ? tables[i].index - min : result;
        min = min > tables[i].index ? tables[i].index : min;
    }
    return result;
}


int main() {
    int nums[] = {9, 8, 1, 0, 1, 9, 4, 0, 4, 1};
    printf("%d", maxWidthRamp(nums, sizeof(nums) / sizeof(nums[0])));
    return 0;
}
