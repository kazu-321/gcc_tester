#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if(a>=b) {
        printf("a: %lf   b: %lf\n", a, b);
    } else {
        printf("b: %lf   a: %lf\n", b, a);
    }
    return 0;
}