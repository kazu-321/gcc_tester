#include <stdio.h>
#include <stdlib.h>

int *make_even(int num);

int main(void)
{
    int i;
    int *array;
    printf("---make_even(7)---\n");
    array = make_even(7);
    for(i=0; i<7; i++) {
    printf("%d ", *(array+i));
    }
    printf("\n");
    free(array);
    printf("---make_even(10)---\n");
    array = make_even(10);
    for(i=0; i<10; i++) {
    printf("%d ", *(array+i));
    }
    printf("\n");
    free(array);

    return 0;
}

int *make_even(int num)
{
    int i;
    int *array;
    array = (int *)malloc(sizeof(int) * num);
    if(array == NULL) {
        printf("メモリの確保に失敗しました\n");
        exit(1);
    }
    for(i=0; i<num; i++) {
        *(array+i) = i * 2;
    }
    return array;
}