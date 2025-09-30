#include <stdio.h>
#include <string.h>

int main(void) {
    char str[1024];
    int count[10] = {0};
    int i;

    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count[str[i] - '0']++;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d: %d\n", i, count[i]);
    }

    return 0;
}