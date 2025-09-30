/*
ibarakikousenkokusai kogakuka の 19 文字目に sozo を挿入するプログラム

strinsでは、19まではstr1をそのままコピーし、20からはstr2をコピーし、
その後にstr1の20文字目以降をコピーする。
*/



#include <stdio.h>
#include <string.h>
char *strins(char *str1, char *str2, int start) {
    int c1, len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 < len2 || start >= len1)
        return (str1);
    for (c1 = len1; c1 >= start; c1--)
        str1[c1 + len2] = str1[c1];
    for (c1 = 0; c1 < len2; c1++)
        str1[start + c1] = str2[c1];
    return (str1);
}

int main(void) {
    char str1[128], str2[128];
    strcpy(str1, "ibarakikosenkokusaikogakuka");
    strcpy(str2, "sozo");
    printf("str1=%s\n", str1);
    printf("str2=%s\n", str2);
    printf("%s\n", strins(str1, str2, 19));
    return (0);
}