#include <stdio.h>

void my_strcpy(char *dest, const char *src) {
    while (*src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0'; // Null-terminate the destination string
}

int main(void) {
    char str1[1024] = "ibaraki";
    char str2[1024] = "kosen";

    my_strcpy(str1, str2);
    printf("%s\n", str1);

    return 0;
}