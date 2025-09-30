#include <stdio.h>

int main(void) {
    char data[3][128] = {"Hello", "Goodbye", "Thankyou"};
    for(int i = 0; i < 3; i++) {
        printf("%s\n", data[i]);
    }
    return 0;
}