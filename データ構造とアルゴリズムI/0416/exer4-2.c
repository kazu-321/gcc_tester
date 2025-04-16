#include "stdio.h"

int main() {
    int score[3][5];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &score[i][j]);
        }
    }
    printf("  　　英　数　国　理　社\n");
    for(int i = 0; i < 3; i++) {
        printf("%d 番　", i + 1);
        for(int j = 0; j < 5; j++) {
            printf("%02d　", score[i][j]);
        }
        printf("\n");
    }
}