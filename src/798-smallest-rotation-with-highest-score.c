#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calcScore(int *nums, int numsSize) {
    int result = 0;
    for (int i = 0; i < numsSize; i++) {
        result += nums[i] <= i;
    }
    return result;
}

void reverse(int *nums, int start, int end) {
    int tmp;
    while (start < end) {
        tmp = nums[start];
        nums[start++] = nums[end];
        nums[end--] = tmp;
    }
}

// bruteforce, very slow. To be updated.
int bestRotation(int* A, int ASize) {
    int maxScore = calcScore(A, ASize);
    int result = 0;
    int currScore;
    int *dup = malloc(ASize * sizeof(int));
    for (int i = 1; i < ASize; i++) {
        memcpy(dup, A + i, (ASize - i)*sizeof(int));
        memcpy(dup + ASize - i, A, i * sizeof(int));
        //reverse(A, 0, i-1);
        //reverse(A, i, ASize - 1);
        //reverse(A, 0, ASize - 1);
        currScore = calcScore(dup, ASize);
        if (currScore > maxScore) {
            maxScore = currScore;
            result = i;
        }
        //reverse(A, 0, ASize - 1);
        //reverse(A, i, ASize - 1);
        //reverse(A, 0, i-1);
    }
    return result;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test a b c d ....\n");
        exit(-1);
    }
    int *nums = malloc((argc - 1) * sizeof(int));
    for (int i = 0; i < argc - 1; i++) {
        nums[i] = atoi(argv[i + 1]);
    }
    printf("%d", bestRotation(nums, argc - 1));
    free(nums);
    return 0;
}
