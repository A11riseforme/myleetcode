#include <stdio.h>
#include <limits.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    int end = 0;
    int start = 0;
    int sum = 0;
    int result = INT_MAX;
    while (end < numsSize) {
        sum += nums[end];
        if (sum >= s) {
            while (start <= end) {
                sum -= nums[start++];
                if (sum < s) {
                    int interv = end - start + 2;
                    result = end - start + 2 < result ? end - start + 2 : result;
                    break;
                }
            }
        }
        end++;
    }
    return result == INT_MAX ? 0 : result;
}


int main() {
    int nums[] = {2,3,1,2,4,3};
    printf("%d",minSubArrayLen(7, nums, 6));
}
