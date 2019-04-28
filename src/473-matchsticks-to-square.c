#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

bool dfs(int *nums, int numsSize, int side, int *sides, int index)
{
    if (index == numsSize)
    {
        return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
    }
    int curr = nums[index];
    for (int i = 0; i < 4; ++i)
    {
        if (sides[i] + curr > side)
        {
            continue;
        }
        sides[i] += curr;
        if (dfs(nums, numsSize, side, sides, index + 1))
        {
            return true;
        }
        sides[i] -= curr;
    }
    return false;
}

int compare_ints(const void *a, const void *b)
{
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    if (arg1 < arg2)
    {
        return 1;
    }
    if (arg1 > arg2)
    {
        return -1;
    }
    return 0;
}

bool makesquare(int *nums, int numsSize)
{
    if (numsSize < 4)
    {
        return false;
    }
    int sum = 0;
    for (int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
    }
    if (sum % 4)
    {
        return false;
    }
    int side = sum >> 2;
    int sides[4] = {0};
    qsort(nums, numsSize, sizeof(nums[0]), compare_ints);
    return dfs(nums, numsSize, side, sides, 0);
}

int main(int argc, char **argv)
{
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int nums[] = {1, 1, 2, 2, 2};
    printf("%s\n", makesquare(nums, sizeof(nums) / sizeof(nums[0])) ? "yes" : "no");
    return 0;
}