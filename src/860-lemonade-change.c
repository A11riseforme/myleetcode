#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool lemonadeChange(int *bills, int billsSize) {
    int nums[2] = {0, 0};
    for (int i = 0; i < billsSize; ++i) {
        if (bills[i] == 5) {
            ++nums[0];
            continue;
        } else if (bills[i] == 10) {
            if (nums[0] == 0) {
                return false;
            }
            ++nums[1];
            --nums[0];
            continue;
        } else if (bills[i] == 20) {
            if (nums[0] >= 1 && nums[1] >= 1) {
                --nums[0];
                --nums[1];
                continue;
            } else if (nums[0] >= 3) {
                nums[0] -= 3;
                continue;
            } else {
                return false;
            }
        }
    }
    return true;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int bills[] = {5, 5, 5, 10, 20};
    printf("%s\n", lemonadeChange(bills, sizeof(bills) / sizeof(bills[0]))
                       ? "yes"
                       : "no");
    return 0;
}