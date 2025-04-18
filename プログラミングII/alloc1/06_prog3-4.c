#include <stdio.h>
#include <stdlib.h>

char *fill_alpha(int num);

int main(void)
{
    char *mystr;

    printf("---fill_alpha(5)---\n");
    mystr = fill_alpha(5);
    printf("mystr: %s\n", mystr);
    free(mystr);
    printf("---fill_alpha(20)---\n");
    mystr = fill_alpha(20);
    printf("mystr: %s\n", mystr);
    free(mystr);
    
    return 0;
}

char *fill_alpha(int num)
{
    char *str;
    int i;

    str = (char *)malloc(sizeof(char) * (num + 1));
    if (str == NULL) {
        printf("メモリの確保に失敗しました\n");
        exit(1);
    }
    for (i = 0; i < num; i++) {
        str[i] = 'a' + i;
    }
    str[num] = '\0';
    
    return str;
}