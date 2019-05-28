#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxSatisfied(int *customers, int customersSize, int *grumpy, int grumpySize,
                 int x) {
    int sum = 0;
    for (int i = 0; i < customersSize; ++i) {
        sum += customers[i] * (grumpy[i] == 0);
    }
    // cout << sum << endl;
    int diff = 0;
    for (int i = 0; i < x; ++i) {
        diff += (grumpy[i] == 1) * customers[i];
    }
    int maxi = diff;
    // cout << maxi << endl;
    for (int i = 1; i <= customersSize - x; ++i) {
        diff -= (grumpy[i - 1] == 1) * customers[i - 1];
        // cout << diff << endl;
        diff += (grumpy[i + x - 1] == 1) * customers[i + x - 1];
        // cout << diff << endl;
        maxi = fmax(diff, maxi);
        // cout << i << " " << diff << endl;
    }
    return sum + maxi;
}

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int customers[] = {1, 0, 1, 2, 1, 1, 7, 5};
    int grumpy[] = {0, 1, 0, 1, 0, 1, 0, 1};
    int x = 3;
    printf("%d\n",
           maxSatisfied(customers, sizeof(customers) / sizeof(customers[0]),
                        grumpy, sizeof(grumpy) / sizeof(grumpy[0]), x));
    return 0;
}