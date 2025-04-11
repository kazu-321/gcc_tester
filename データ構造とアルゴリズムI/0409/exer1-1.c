#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double x = (double)(a + b + c) / 3;
    printf("%.2f\n", x);
    return 0;
}