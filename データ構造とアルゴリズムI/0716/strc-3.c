#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score_math;
    int Score_english;
    float Average;
};

int main() {
    struct data_struct data[6] = {
        {1, "James", 78, 67, 0.0},
        {2, "John", 92, 82, 0.0},
        {3, "Mary", 85, 79, 0.0},
        {4, "Susan", 78, 81, 0.0},
        {5, "Brian", 72, 82, 0.0},
        {6, "Ruth", 84, 77, 0.0}
    };
    for (int i = 0; i < 6; i++) {
        data[i].Average = (data[i].Score_math + data[i].Score_english) / 2.0;
    }
    printf(" No. |  Name  | Math. | Eng. | Ave. |\n");
    for (int i = 0; i < 6; i++) {
        printf("  %1d  | %5s  |  %2d   |  %2d  | %.1f |\n", 
               data[i].No, data[i].Name, 
               data[i].Score_math, data[i].Score_english, 
               data[i].Average);
    }
    return 0;
}