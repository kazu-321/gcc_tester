#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {
    char str[1024];
    int i, len;

    scanf("%s",str);
    
    len = strlen(str);

    srand((unsigned int)time(NULL));

    if (len > 0) {
        int rand_index = rand() % len;
        printf("入力された文字列: %s\n", str);
        printf("ランダムに選ばれた文字: %c (位置: %d)\n", str[rand_index], rand_index);
    } else {
        printf("文字列が入力されていません。\n");
    }

    return 0;
}

/*
【プログラムの説明】
このプログラムは、ユーザーから文字列を入力として受け取り、その中からランダムに1文字を選んで表示します。
- まず、標準入力から文字列を受け取ります。
- 乱数を初期化し、文字列の長さの範囲でランダムな位置を決めます。
- その位置の文字を表示します。
- 文字列が空の場合は、その旨を表示します。

【実行例】
文字列を入力してください: HelloWorld
入力された文字列: HelloWorld
ランダムに選ばれた文字: o (位置: 4)
*/