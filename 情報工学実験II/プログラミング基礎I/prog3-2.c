#include <stdio.h>

int my_strlen(const char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

int main(void) {
    char str[1024];
    scanf("%s", str);
    printf("文字列の長さは %d です。\n", my_strlen(str));
    return 0;
}