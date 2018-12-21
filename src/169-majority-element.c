#include <stdio.h>
#include <stdlib.h>

/**
 * Majority Vote Algorithm: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/example.html
 *
 */
int majorityElement(int* nums, int numsSize) {
    int candidate;
    int count = 0;
    for(int i = 0; i < numsSize; i += 1) {
        if(count == 0) {
            candidate = nums[i];
            count += 1;
        } else {
            if(nums[i] == candidate) {
                count += 1;
            } else {
                count -= 1;
            }
        }
    }
    return candidate;
}


int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./test target n1 n2...\n");
        exit(-1);
    }

    int i, count = argc - 1;
    int *nums = malloc(count * sizeof(int));
    for (i = 0; i < count; i++) {
        nums[i] = atoi(argv[i + 1]);
    }

    printf("%d\n", majorityElement(nums, count));
    free(nums);
}
