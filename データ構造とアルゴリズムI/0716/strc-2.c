#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score;
    char Grade;
};

int main() {
    struct data_struct data[4] = {
        {1, "James", 78, 'B'},
        {2, "John", 92, 'A'},
        {3, "Mary", 85, 'A'},
        {4, "Susan", 78, 'B'}
    };

    printf(" No. |  Name  | Score | Grade |\n");
    for (int i = 0; i < 4; i++) {
        printf("  %1d  | %5s  |  %2d   |   %c   |\n", data[i].No, data[i].Name, data[i].Score, data[i].Grade);
    }
    return 0;
}