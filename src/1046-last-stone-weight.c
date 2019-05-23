#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    int arg1 = *(const int *)a;
    int arg2 = *(const int *)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

int lastStoneWeight(int *s, int size) {
    while (size > 1) {
        qsort(s, size, sizeof(int), cmp);
        s[size - 2] = s[size - 1] - s[size - 2];
        size--;
    }

    return s[0];
}

/*
// clearly a heap/priority_queue would be most efficient way of solving this qn
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> asdf(stones.begin(), stones.end());
        while (asdf.size() > 1) {
            auto a = asdf.top();
            asdf.pop();
            auto b = asdf.top();
            asdf.pop();
            //cout << a << " " << b << endl;
            if (a != b) {
                asdf.push(a-b);
            }
        }
        if (asdf.size() != 0) {
            return asdf.top();
        } else {
            return 0;
        }
    }
};
*/

int main(int argc, char **argv) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number ...\n");
        exit(-1);
    }
    */
    int s[] = {2, 7, 4, 1, 8, 1};
    printf("%d\n", lastStoneWeight(s, sizeof(s) / sizeof(s[0])));
    return 0;
}