#include <stdio.h>

double myPositivePow(double x, int n) {
    if (n == 0) { return 1.0; }
    if (n == 1) { return x; }
    double t = myPositivePow(x, n / 2);
    return n % 2 == 0 ? t * t : t * t * x;
}


double myPow(double x, int n) {
    return n < 0 ? 1 / myPositivePow(x, -n) : myPositivePow(x, n);
}


int main() {
    double x = 1.99;
    int n = 10;
    printf("%lf", myPow(x, n));
}
