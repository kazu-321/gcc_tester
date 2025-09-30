#include <stdio.h>

int main(void) {
    printf("char型のバイト数: %zuバイト\n", sizeof(char));
    printf("char型のビット数: %zuビット\n", sizeof(char) * 8);
    return 0;
}