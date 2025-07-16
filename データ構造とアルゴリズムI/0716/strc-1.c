#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score;
    char Grade;
};

int main() {
    struct data_struct data;
    data.No = 1;
    strcpy(data.Name, "James");
    data.Score = 78;
    data.Grade = 'B';
    printf(" No. |  Name  | Score | Grade |\n");
    printf("  %1d  | %5s  |  %2d   |   %c   |\n", data.No, data.Name, data.Score, data.Grade);
    return 0;
}