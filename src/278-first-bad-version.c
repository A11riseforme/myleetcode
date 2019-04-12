#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int l = 1,r=n;
    int long mid;
    while (l<r) {
        mid = l+(r-l)/2;
        if (!isBadVersion(mid)) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    return l;
}


int main(int argc, char **argv) {
    /*
    if (argc < 3 ) {
        fprintf(stderr, "Usage: ./test pattern query1 query2 ...");
        exit(-1);
    }
    */
    printf("I am too lazy to code the test cases\n");
    return 0;
}

