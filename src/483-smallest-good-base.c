#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool check_smallbase(long num, long base) {
    ldiv_t ans = ldiv(num, base);
    if (ans.rem != 1) {
        return false;
    }
    // num = 1
    if (ans.quot == 0) {
        return true;
    } else
        return check_smallbase(ans.quot, base);
}

// for algorithm wise, check https://leetcode.com/problems/smallest-good-base/discuss/96587/Python-solution-with-detailed-mathematical-explanation-and-derivation
char* smallestGoodBase(char* n) {
    long num = atol(n);
    int maxPower = log2(num);
    char *result = malloc(32);
    long tmpBase;
    bool found = false;
    for (int i = maxPower; i >= 2; i--) {
        tmpBase = pow(num, 1.0/i);
        if (check_smallbase(num, tmpBase)) {
            found = true;
            break;
        }
    }
    if (!found) {
        tmpBase = num-1;
    }
    snprintf(result, 32, "%ld", tmpBase);
    return result;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test string1\n");
        exit(-1);
    }
    printf("smallest good base of %s is %s", argv[1], smallestGoodBase(argv[1]));
    return 0;
}
