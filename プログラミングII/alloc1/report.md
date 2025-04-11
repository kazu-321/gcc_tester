# sample103-1.c

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

## ✅ Test  passed
### 入力:
```

```
### 出力:
```
---show_range(test, 2, 4)---
*ptr+2: 55, ptr+2: 0x7ffe52019488
*ptr+3: 22, ptr+3: 0x7ffe5201948c
*ptr+4: 75, ptr+4: 0x7ffe52019490
---show_range(test, 1, 3)---
*ptr+1: 60, ptr+1: 0x7ffe52019484
*ptr+2: 55, ptr+2: 0x7ffe52019488
*ptr+3: 22, ptr+3: 0x7ffe5201948c

```

==========================

- ✅ Passed: 1
- ❌ Failed: 0 

# sample103-1.c
## code

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

## ✅ Test  passed
### 入力:
```

```
### 出力:
```
---show_range(test, 2, 4)---
*ptr+2: 55, ptr+2: 0x7ffc1df86da8
*ptr+3: 22, ptr+3: 0x7ffc1df86dac
*ptr+4: 75, ptr+4: 0x7ffc1df86db0
---show_range(test, 1, 3)---
*ptr+1: 60, ptr+1: 0x7ffc1df86da4
*ptr+2: 55, ptr+2: 0x7ffc1df86da8
*ptr+3: 22, ptr+3: 0x7ffc1df86dac

```

==========================

- ✅ Passed: 1
- ❌ Failed: 0 

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
## ✅ Test  passed
### 入力:
```

```
### 出力:
```
---show_range(test, 2, 4)---
*ptr+2: 55, ptr+2: 0x7ffe624056a8
*ptr+3: 22, ptr+3: 0x7ffe624056ac
*ptr+4: 75, ptr+4: 0x7ffe624056b0
---show_range(test, 1, 3)---
*ptr+1: 60, ptr+1: 0x7ffe624056a4
*ptr+2: 55, ptr+2: 0x7ffe624056a8
*ptr+3: 22, ptr+3: 0x7ffe624056ac

```

==========================

- ✅ Passed: 1
- ❌ Failed: 0 

