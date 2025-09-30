#include <stdio.h>
#include <string.h>


int main(void) {
    char str[1024];

    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            printf("%d番目\n", i + 1);
        }
    }

    return 0;
}