#include <stdio.h>

void my_strcat(char *dest, const char *src) {
    while (*dest) {
        dest++;
    }
    while (*src) {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int main(void) {
    char str1[1024] = "ibaraki";
    char str2[1024] = "kosen";

    my_strcat(str1, str2);
    printf("%s\n", str1);

    return 0;
}