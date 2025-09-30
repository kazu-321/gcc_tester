# exer5-1.c
## code
```c

#include <stdio.h>

int main() {
    int a, b, m, n;
    scanf("%d %d", &a, &b);
    m = a;
    n = b;
    while(m!=n) {
        if(m > n) {
            m = m-n;
        } else {
            n = n-m;
        }
    }
    printf("%d\n", m);
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
24
18
```
### 出力:
```
6
``` 

