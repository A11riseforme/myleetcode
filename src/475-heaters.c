#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX(a,b) ((a)>(b)?(a):(b))

int cmp(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int findRadius(int* houses, int housesSize, int* heaters, int heatersSize) {
    qsort(houses, housesSize, sizeof(*houses), cmp);
    qsort(heaters, heatersSize, sizeof(*heaters), cmp);
    int i, j = 0;
    int result = 0;
    for (int i = 0; i < housesSize; ++i) {
        int cur = houses[i];
        while (j < heatersSize - 1 && abs(heaters[j + 1] - cur) <= abs(heaters[j] - cur)) {
            ++j;
        }
        result = MAX(result, abs(heaters[j] - cur));
    }
    return result;
}

int main() {
    int houses[] = {1, 2, 3, 4};
    int heaters[] = {1, 4};
    printf("%d", findRadius(houses, 4, heaters, 2));
    return 0;
}
