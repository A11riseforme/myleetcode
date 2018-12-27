#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    int num = 0;
    // if can plant a flower at the start.
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        flowerbed[0] = 1;
        num++;
    }
    // if can plant a flower at the end.
    if (flowerbed[flowerbedSize-2] == 0 && flowerbed[flowerbedSize-1] == 0) {
        flowerbed[flowerbedSize-1] = 1;
        num++;
    }
    // scan through the flowerbed from the second till the second last.(first and last has been considered previously.)
    for (int i = 0; i < flowerbedSize-1; i++) {
        if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
            flowerbed[i] = 1;
            num++;
        }
    }
    return num >= n;
}


int main() {
    int flowerbed[] = {1,0,0,0,1};
    int n = 1;
    printf("can %splant %d flower(s)", canPlaceFlowers(flowerbed, 5, n) ? "" : "not ", n);
}
