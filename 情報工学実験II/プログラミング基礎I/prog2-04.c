#include <stdio.h>

int main(void) {
    char input;
    scanf("%c", &input);
    if(input == 'A') {
        printf("正解です\n");
    } else {
        printf("誤りです\n");
    }
    return 0;
}