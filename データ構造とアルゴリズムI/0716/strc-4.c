#include <stdio.h>
#include <string.h>
#include <math.h>

struct data_struct {
    char Name[128];
    int Score;
};

int main() {
    FILE *fp = fopen("データ構造とアルゴリズムI/0716/data.txt", "r");
    if (fp == NULL) {
        printf("Failed to open data.txt\n");
        return 1;
    }

    struct data_struct data[50];
    int i = 0;
    int sigma_score = 0;

    char tmp_name[128];
    int tmp_score;
    while (fscanf(fp, "%s %d", tmp_name, &tmp_score) == 2) {
        strcpy(data[i].Name, tmp_name);
        data[i].Score = tmp_score;
        sigma_score += tmp_score;
        i++;
    }

    fclose(fp);

    float average_score = (float)sigma_score / i;
    printf("Average Score: %.2f\n", average_score);

    float variance = 0.0f;
    for (int j = 0; j < i; j++) {
        float diff = data[j].Score - average_score;
        variance += diff * diff;
    }
    variance /= i;
    float standard_deviation = sqrt(variance);
    printf("Standard Deviation: %.2f\n", standard_deviation);

    printf("Students with scores 85 or above:\n");
    printf("  Name  | Score |\n");
    int count = 0;
    for (int j = 0; j < i; j++) {
        if (data[j].Score >= 85) {
            printf("%7s |  %d   |\n", data[j].Name, data[j].Score);
            count++;
        }
    }
    printf("Total students with scores 85 or above: %d\n", count);
}