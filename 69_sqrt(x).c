#include <stdio.h>

// newton's algorithm, can be optimized using
// fast square root algorithm with magic number 0x5F3759DF.
int mySqrt(int x) {
    if (x == 1 || x == 0) {
        return x;
    }
    double result = x/2;
    for(int i = 0; i < 20; i++) {
        result = (result + x / result) / 2;
    }
    return (int)result;
}


int main() {
    printf("integer square root of 12345 is %d", mySqrt(12345));
}
