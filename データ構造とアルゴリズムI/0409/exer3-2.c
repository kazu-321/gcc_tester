#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int count = 0;
    while(count < a) {
        count++;
        printf("*");
        if(count%20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}