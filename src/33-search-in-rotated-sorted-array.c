#include <stdio.h>

int search(int *nums, int numsSize, int target) {
    int pos = revisedSearch(nums, 0, numsSize-1, target);
    return pos;
}


long binarySearch(int *nums, int i, int j, int target) {
  if (j < i) {
    return -1;
  }
  long mid = (i+j)/2;
  if (nums[mid] == target) {
    return mid;
  }
  if (nums[mid] > target) {
    return binarySearch(nums, i, mid-1, target);
  }
  return binarySearch(nums, mid+1, j, target);
}


int revisedSearch(int *nums, int i, int j, int target) {
    if (j < i) {
        return -1;
    }

    long mid = (i + j) / 2;
    if (nums[mid] == target) {
        return mid;
    }

    if (nums[i] < nums[mid]) {
        if (nums[i] <= target && target <= nums[mid]) {
            return binarySearch(nums, i, mid - 1, target);
        }
        return revisedSearch(nums, mid + 1, j, target);
    }

    if (nums[mid + 1] <= target && target <= nums[j]) {
        return binarySearch(nums, mid + 1, j, target);
    }
    return revisedSearch(nums, i, mid - 1, target);
}


int main() {
    int nums[] = {6,8,9,1,3,4,5};
    int pos = search(nums, 7, 3);
    printf("%d",pos);
}
