#include <stdio.h>

int main(void) {
    char arr[] = "oiibkayrrawkqiykpoasjebn";
    int i;
    int len = 0;
    while (arr[len] != '\0') {
        len++;
    }

    for (i = 1; i < len; i += 2) {
        putchar(arr[i]);
    }
    putchar('\n');

    return 0;
}