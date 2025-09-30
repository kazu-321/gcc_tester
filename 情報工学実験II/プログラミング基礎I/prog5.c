#include <stdio.h>
#include <string.h>


int main() {
    char str[1024];
    int slide, i;
    scanf("%s", str);
    scanf("%d", &slide);

    int len = strlen(str);
    for (i = 0; i < len; i++) {
        if ('a' <= str[i] && str[i] <= 'z') {
            char shifted = ((str[i] - 'a' + slide) % 26) + 'a';
            printf("%c", shifted);
        } else {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}