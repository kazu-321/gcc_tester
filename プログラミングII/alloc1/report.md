# sample103-1.c
## code
```c

#include <stdio.h>
#include <stdlib.h>

int main(void) 
{
    char *str;
    int num, i;
    
    printf("num > ");
    scanf("%d", &num);

    str = (char *)malloc(sizeof(char)*(num+1));
    if(str==NULL) {
        printf("not allocated.\n");
        return 1;
    }

    for(i=0; i<num; i++) {
        *(str+i) = 'a';
    }
    *(str+i) = '\0';
    printf("str: %s\n", str);

    free(str);

    return 0;    
}

```
## result
## ✅ Test 1 passed
### 入力:
```
10
```
### 出力:
```
num > str: aaaaaaaaaa

```
## ✅ Test 2 passed
### 入力:
```
5
```
### 出力:
```
num > str: aaaaa

```

==========================

- ✅ Passed: 2
- ❌ Failed: 0 

# sample103-2.c
## code
```c

#include <stdio.h>

void show_range(int *ptr, int s, int e);

void show_range(int *ptr, int s, int e)
{
    int i;
    for(i=s; i<=e; i++) {
        printf("*ptr+%d: %d, ptr+%d: %p\n", i, *(ptr+i), i, ptr+i);
    }
}

int main(void)
{
    int test[5] = {80, 60, 55, 22, 75};
    printf("---show_range(test, 2, 4)---\n");
    show_range(test, 2, 4);
    printf("---show_range(test, 1, 3)---\n");
    show_range(test, 1, 3);
    return 0;
}

```
## result
## ✅ Test  passed
### 入力:
```

```
### 出力:
```
---show_range(test, 2, 4)---
*ptr+2: 55, ptr+2: 0x7ffce5a54a28
*ptr+3: 22, ptr+3: 0x7ffce5a54a2c
*ptr+4: 75, ptr+4: 0x7ffce5a54a30
---show_range(test, 1, 3)---
*ptr+1: 60, ptr+1: 0x7ffce5a54a24
*ptr+2: 55, ptr+2: 0x7ffce5a54a28
*ptr+3: 22, ptr+3: 0x7ffce5a54a2c

```

==========================

- ✅ Passed: 1
- ❌ Failed: 0 

