#include "stdio.h"

int main() {
    int score[3][5];
    int sum[3] = {0};
    int subject_sum[5] = {0};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &score[i][j]);
            sum[i] += score[i][j];
            subject_sum[j] += score[i][j];
        }
    }
    printf("        英    数    国    理    社    平均点\n");
    for(int i = 0; i < 3; i++) {
        printf("%d 番    ", i + 1);
        for(int j = 0; j < 5; j++) {
            printf("%02d    ", score[i][j]);
        }
        printf("%02.1f\n", sum[i] / 5.);
    }
    printf("平均点 ");
    for(int j = 0; j < 5; j++) {
        printf("%02.1f  ", subject_sum[j] / 3.);
    }
    printf("\n");
}