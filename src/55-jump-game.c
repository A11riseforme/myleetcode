#include <stdio.h>
#include <stdbool.h>

//time limit exceeded for the last test case.
bool jump(int *nums, int startPos, int endPos) {
    int steps = nums[startPos];
    if (steps >= endPos - startPos) {
        return true;
    } else if (steps != 0) {
        for (int i = 1; i <= steps; i++) {
            if (nums[startPos + i] != 0) {
                if (jump(nums, startPos + i, endPos)) {
                    return true;
                }
            }
        }
        return false;
    }
    return false;
}


bool canJumpSlow(int *nums, int numsSize) {
    bool result = jump(nums, 0, numsSize - 1);
    return result;
}


//dp
bool canJump(int *nums, int numsSize) {
    int furthestPos = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        // i > furthestPos : cannot even reach point i
        // i is before the end point, so just quit.
        if (i > furthestPos) {
            return false;
            // numsSize-1 < furthestPos : has gone beyond the end point
            // so can reach the end.
        } else if (numsSize - 1 < furthestPos) {
            return true;
        }
        furthestPos = i + nums[i] < furthestPos ? furthestPos : i + nums[i];
    }
    return furthestPos >= numsSize - 1;
}


int main() {
    int steps[] = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
    if (canJump(steps, 12)) {
        printf("can jump to the end point\n");
    } else {
        printf("cannot jump to the end point\n");
    }
}
