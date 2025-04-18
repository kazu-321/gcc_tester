#include <stdio.h>
#include <stdlib.h>

int main() {
    int *array;
    int num, i;
    printf("num > ");
    scanf("%d", &num);
    array = (int *)malloc(num * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (i = 0; i < num; i++) {
        array[i] = 7;
    }
    for (i = 0; i < num; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}