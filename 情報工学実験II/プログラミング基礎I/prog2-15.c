#include <stdio.h>

int main(void) {
    char day[7][10] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday"
    };
    int i;
    printf("0-月曜日 1-火曜日 2-水曜日 3-木曜日 4-金曜日 5-土曜日 6-日曜日\n");
    scanf("%d", &i);
    printf("%s\n", day[i]);
    return 0;
}