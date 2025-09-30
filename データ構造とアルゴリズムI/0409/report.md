# exer1-1.c
## code
```c

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    double x = (double)(a + b + c) / 3;
    printf("%.2f\n", x);
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
0 0 0
```
### 出力:
```
0.00
```
## ✅ Test 1 passed
### 入力:
```
1 2 3
```
### 出力:
```
2.00
```
## ✅ Test 2 passed
### 入力:
```
10 20 30
```
### 出力:
```
20.00
``` 

# exer1-2.c
## code
```c

#include <stdio.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    if(a>=b) {
        printf("a: %lf   b: %lf\n", a, b);
    } else {
        printf("b: %lf   a: %lf\n", b, a);
    }
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
1.23 4.56
```
### 出力:
```
b: 4.560000   a: 1.230000
```
## ✅ Test 1 passed
### 入力:
```
4.56 1.23
```
### 出力:
```
a: 4.560000   b: 1.230000
``` 

# exer2-1.c
## code
```c

#include <stdio.h>

int main() {
    // add ascii table
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            printf("%2d  ", (i + 1) * (j + 1));
        }
        printf("\n");
    }
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```

```
### 出力:
```
1   2   3   4   5   6   7   8   9  
 2   4   6   8  10  12  14  16  18  
 3   6   9  12  15  18  21  24  27  
 4   8  12  16  20  24  28  32  36  
 5  10  15  20  25  30  35  40  45  
 6  12  18  24  30  36  42  48  54  
 7  14  21  28  35  42  49  56  63  
 8  16  24  32  40  48  56  64  72  
 9  18  27  36  45  54  63  72  81
``` 

# exer2-2.c
## code
```c

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
12
```
### 出力:
```
6
```
## ✅ Test 1 passed
### 入力:
```
5
```
### 出力:
```
2
```
## ✅ Test 2 passed
### 入力:
```
120
```
### 出力:
```
16
``` 

# exer3-1.c
## code
```c

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if((a==b) && (b==c)) {
        printf("三つの値は等しい\n");
    } else
    if ((a==b) ||
        (b==c) ||
        (c==a)) {
        printf("二つの値が等しい\n");
    } else {
        printf("三つの値は異なる\n");
    }
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
1 2 3
```
### 出力:
```
三つの値は異なる
```
## ✅ Test 1 passed
### 入力:
```
1 1 2
```
### 出力:
```
二つの値が等しい
```
## ✅ Test 2 passed
### 入力:
```
2 1 1
```
### 出力:
```
二つの値が等しい
```
## ✅ Test 3 passed
### 入力:
```
1 2 1
```
### 出力:
```
二つの値が等しい
```
## ✅ Test 4 passed
### 入力:
```
1 1 1
```
### 出力:
```
三つの値は等しい
``` 

# exer3-2.c
## code
```c

#include <stdio.h>

int main() {
    int a;
    scanf("%d", &a);
    int count = 0;
    while(count < a) {
        count++;
        printf("*");
        if(count%20 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
```
## result
## ✅ Test 0 passed
### 入力:
```
10
```
### 出力:
```
**********
```
## ✅ Test 1 passed
### 入力:
```
30
```
### 出力:
```
********************
**********
``` 

