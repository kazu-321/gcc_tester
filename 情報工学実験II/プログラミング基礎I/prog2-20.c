#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char str[1024];
    int i = 0;
    scanf("%s", str);

    while (str[i] != '\0' && str[i] != '\n')
    {
        if (!isdigit((unsigned char)str[i]))
        {
            printf("%c", str[i]);
        }
        i++;
    }
    printf("\n");

    return 0;
}
