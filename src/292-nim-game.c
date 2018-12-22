#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// if there are 4n stones, and you remove first.
// Given the other player very smart, you will always lose.
// you take x stones,(x = 1, 2, 3), your friend takes 4 - x stones.
// so only if number of stones is not multiple of 4, you will win by
// removing number of stones such that 4n stones are left.
bool canWinNim(int n) {
    return (n % 4 != 0);
}


int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: ./test number\n");
        exit(-1);
    }

    printf("you can %swin", canWinNim(atoi(argv[1])) ? "" : "not ");
    return 0;
}
