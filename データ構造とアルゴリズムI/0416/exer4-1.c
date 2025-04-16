#include "stdio.h"

int main() {
    int score[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &score[i]);
    }

    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += score[i];
    }
    double avg = sum / 5.0;
    printf("sum: %d\n", sum);
    printf("avg: %.1f\n", avg);
}