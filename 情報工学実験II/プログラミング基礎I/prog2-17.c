#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1024];
    int count = 0;

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'b') {
            count++;
        }
    }

    if (count > 0) {
        printf("文字 'b' は %d 個含まれています。\n", count);
    } else {
        printf("文字 'b' は含まれていません。\n");
    }

    return 0;
}