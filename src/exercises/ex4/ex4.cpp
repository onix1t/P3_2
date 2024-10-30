#include "ex4.h"

double power(double a, int n) {
    if (n == 0) {
        return 1;
    }

    double halfPower = power(a, n / 2);

    if (n % 2 == 0) {
        return halfPower * halfPower;
    } else {
        return a * halfPower * halfPower;
    }
}
