#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if(a>=b) {
        printf("a: %lf\tb: %lf\n", a, b);
    } else {
        printf("b: %lf\ta: %lf\n", b, a);
    }
    return 0;
}