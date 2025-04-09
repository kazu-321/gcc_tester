#include <stdio.h>

int main() {
    // add ascii table
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%2d  ", (i + 1) * (j + 1));
        }
        printf("\n");
    }
    return 0;
}