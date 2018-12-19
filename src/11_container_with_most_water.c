#include <stdio.h>
#include <stdbool.h>

//very intuitive method, but inefficient.
int inefficient_maxArea(int* height, int heightSize) {
    int first = *height > *(height + 1) ? *height : *(height + 1);
    int second = *height + *(height + 1) - first;
    for (int i = 2; i < heightSize; i++) {
        if (*(height + i) > first) {
            second = first;
            first = *(height + i);
        } else if (*(height + i) > second) {
            second = *(height + i);
        }
    }
    int area = 0;
    for (int i = 1; i <= second; i++) {
        int left = 0;
        int right = heightSize - 1;
        while (*(height + left) < i) {
            left++;
        }
        while(*(height + right) < i) {
            right--;
        }
        int width = right - left;
        area = width * i > area ? width * i : area;
    }
    return area;
}


int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    while (left < right) {
        water = (left - right) * (*(height + left) > *(height + right) ? * (height + left) : * (height + right));
        max = (water > max ? water : max);
        if (*(height + left) < * (height + right)) {
            left++;
        } else {
            right--;
        }
    }
    return max;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    printf("%d", maxArea(height, 9));
}
