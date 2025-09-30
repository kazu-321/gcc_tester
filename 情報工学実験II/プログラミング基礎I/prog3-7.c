#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[] = "ibaraki";
    char str2[] = "kosen";
    int result;

    result = strcmp(str1, str2);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    if (result < 0) {
        printf("str1 は str2 より小さいです。\n");
    } else if (result > 0) {
        printf("str1 は str2 より大きいです。\n");
    } else {
        printf("str1 と str2 は等しいです。\n");
    }

    return 0;
}