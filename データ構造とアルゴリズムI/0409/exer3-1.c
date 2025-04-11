#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if((a==b) && (b==c)) {
        printf("三つの値は等しい\n");
    } else
    if ((a==b) ||
        (b==c) ||
        (c==a)) {
        printf("二つの値が等しい\n");
    } else {
        printf("三つの値は異なる\n");
    }
    return 0;
}