#include <stdio.h>

int main(void) {
    char name[]="HashimotoKazusa";
    for(int i=14; i>=0; i--){
        printf("%c", name[i]);
    }
    printf("\n");
    return 0;
}