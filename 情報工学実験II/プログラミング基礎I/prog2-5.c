#include <stdio.h>

int main(void) {
    char input;
    scanf("%c", &input);
    if('A' <= input && input <= 'C') {
        printf("正解です\n");
    } else {
        printf("誤りです\n");
    }
    return 0;
}