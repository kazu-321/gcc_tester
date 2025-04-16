#include "stdio.h"

int main() {
    double a[10];
    a[0] = 1;
    a[1] = 2;
    // 2a_{n+2} - 3a_{n+1} + a_n = 0
    // 2a_{n} - 3a_{n-1} + a_{n-2} = 0
    // 2a_{n} = 3a_{n-1} - a_{n-2}
    // a_{n} = 1.5a_{n-1} - 0.5a_{n-2}
    for (int i = 2; i < 10; i++) {
        a[i] = 1.5 * a[i - 1] - 0.5 * a[i - 2];
    }
    printf("%f\n", a[9]);
    return 0;
}