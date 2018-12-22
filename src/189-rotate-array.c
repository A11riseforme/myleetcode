#include <stdio.h>
#include <stdlib.h>

// standard solution.
void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    if (k == 0) {
        return nums;
    }
    reverse(nums, 0, numsSize - 1 - k);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}

void reverse(int *nums, int start, int end) {
    while (start < end) {
        int tmp = *(nums + start);
        *(nums + start) = *(nums + end);
        *(nums + end) = tmp;
        start += 1;
        end -= 1;
    }
}


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test k n1 n2...\n");
        exit(-1);
    }

    int k = atoi(argv[1]);
    int i, count = argc - 2;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 2]);
    }

    rotate(nums, count, k);

    for (i = 0; i < count; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}
