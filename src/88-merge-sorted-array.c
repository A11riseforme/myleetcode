#include <stdio.h>
#include <stdbool.h>

void merge(int* nums1, int m, int* nums2, int n) {
    while(m > 0 && n > 0) {
        if(nums1[m - 1] > nums2[n - 1]) {
            nums1[m + n - 1] = nums1[m - 1];
            m--;
        } else {
            nums1[m + n - 1] = nums2[n - 1];
            n--;
        }
    }

    while(n > 0) {
        nums1[m + n - 1] = nums2[n - 1];
        n--;
    }

    while(m > 0) {
        nums1[m + n - 1] = nums1[m - 1];
        m--;
    }
}


int main() {
    int nums1[] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    merge(nums1, 3, nums2, 3);
    for (int i = 0; i < sizeof(nums1)/sizeof(int); i++) {
        printf("%d ",nums1[i]);
    }
}
