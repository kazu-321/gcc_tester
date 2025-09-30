#include <stdio.h>

int main(void) {
    char str[3][1024];
    for(int i = 0; i < 3; i++) {
        scanf("%s", str[i]);
    }
    for(int i = 0; i < 3; i++) {
        printf("%s\n", str[i]);
    }
    return 0;
}