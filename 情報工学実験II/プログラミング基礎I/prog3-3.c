#include <stdio.h>
#include <string.h>

int main(void) {
    char str1[1024] = "ibaraki";
    char str2[1024] = "kosen";

    strcpy(str1, str2);
    printf("%s\n", str1);

    return 0;
}