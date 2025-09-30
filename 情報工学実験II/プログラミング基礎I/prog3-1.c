#include <stdio.h>
#include <string.h>

int main(void) {
    char str[256];
    scanf("%s", str);
    printf("文字列の長さは %zu です。\n", strlen(str));
    return 0;
}