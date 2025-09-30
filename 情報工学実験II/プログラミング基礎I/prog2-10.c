#include <stdio.h>

int main(void) {
    char ibaraki[] = "ibaraki";
    int i = 0;
    while(i<7){
        printf("%c/", ibaraki[i]);
        i++;
    }
    printf("\n");
    return 0;
}