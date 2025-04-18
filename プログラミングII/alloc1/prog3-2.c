#include <stdio.h>
#include <stdlib.h>

char *make_string();

int main(void) 
{
    char *mystr;
    mystr = make_string();
    printf("mystr: %s\n", mystr);
    free(mystr);
    return 0; 
}


char *make_string()
{
    char *str;
    int num, i;

    printf("num > ");
    scanf("%d", &num);

    str = (char *)malloc(sizeof(char)*(num+1));
    if(str==NULL) {
        printf("not allocated.\n");
        return NULL;
    }

    for(i=0; i<num; i++) {
        *(str+i) = 'a';
    }
    *(str+i) = '\0';

    return str;
}