#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main(void) {
    char str[MAX_LEN + 1];

    scanf("%100s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            printf("%d番目\n", i + 1);
        }
    }

    return 0;
}