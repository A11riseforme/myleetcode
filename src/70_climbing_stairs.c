#include <stdio.h>

// fibonacci, iterative way.
int climbStairs(int n) {
    if(n == 1) {
        return 1;
    }
    int first = 1;
    int second = 2;
    int i;
    int third;
    for(i = 3; i <= n; i++) {
        third = first + second;
        first = second;
        second = third;
    }
    return second;
}


int main() {
    printf("It has %d ways to climb up to 9 stairs", climbStairs(9));
}
