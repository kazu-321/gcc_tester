#include <stdio.h>

int main(void) {
    char data[1024];
    char c;
    int count = 0;

    scanf("%s", data);
    getchar();
    scanf("%c", &c);

    // 文字列内のcの個数を数える
    for (int i = 0; data[i] != '\0'; i++) {
        if (data[i] == c) {
            count++;
        }
    }

    if (count > 0) {
        printf("'%c' は %d 回含まれています。\n", c, count);
    }
    else {
        printf("'%c' は含まれていません。\n", c);
    }

    return 0;
}