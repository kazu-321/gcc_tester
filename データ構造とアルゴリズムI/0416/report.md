# exer4-1.c
## code
```c

#include "stdio.h"

int main() {
    int score[5];
    for(int i = 0; i < 5; i++) {
        scanf("%d", &score[i]);
    }

    int sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += score[i];
    }
    double avg = sum / 5.0;
    printf("sum: %d\n", sum);
    printf("avg: %.1f\n", avg);
}
```
## result
## ✅ Test 0 passed
### 入力:
```
1 2 3 4 5
```
### 出力:
```
sum: 15
avg: 3.0
```
## ✅ Test 1 passed
### 入力:
```
75
80
99
82
85
```
### 出力:
```
sum: 421
avg: 84.2
``` 

# exer4-2.c
## code
```c

#include "stdio.h"

int main() {
    int score[3][5];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &score[i][j]);
        }
    }
    printf("  　　英　数　国　理　社\n");
    for(int i = 0; i < 3; i++) {
        printf("%d 番　", i + 1);
        for(int j = 0; j < 5; j++) {
            printf("%02d　", score[i][j]);
        }
        printf("\n");
    }
}
```
## result
## ✅ Test 0 passed
### 入力:
```
80 60 22 50 75
90 55 68 72 58
77 67 78 87 65
```
### 出力:
```
英　数　国　理　社
1 番　80　60　22　50　75　
2 番　90　55　68　72　58　
3 番　77　67　78　87　65
```
## ✅ Test 1 passed
### 入力:
```
10
20
30
40
50
20
30
40
50
60
30
40
50
60
70
```
### 出力:
```
英　数　国　理　社
1 番　10　20　30　40　50　
2 番　20　30　40　50　60　
3 番　30　40　50　60　70
``` 

# exer4-3.c
## code
```c

#include "stdio.h"

int main() {
    int score[3][5];
    int sum[3] = {0};
    int subject_sum[5] = {0};
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            scanf("%d", &score[i][j]);
            sum[i] += score[i][j];
            subject_sum[j] += score[i][j];
        }
    }
    printf("        英    数    国    理    社    平均点\n");
    for(int i = 0; i < 3; i++) {
        printf("%d 番    ", i + 1);
        for(int j = 0; j < 5; j++) {
            printf("%02d    ", score[i][j]);
        }
        printf("%02.1f\n", sum[i] / 5.);
    }
    printf("平均点 ");
    for(int j = 0; j < 5; j++) {
        printf("%02.1f  ", subject_sum[j] / 3.);
    }
    printf("\n");
}
```
## result
## ✅ Test 0 passed
### 入力:
```
80 60 22 50 75
90 55 68 72 58
77 67 78 87 65
```
### 出力:
```
英    数    国    理    社    平均点
1 番    80    60    22    50    75    57.4
2 番    90    55    68    72    58    68.6
3 番    77    67    78    87    65    74.8
平均点 82.3  60.7  56.0  69.7  66.0
```
## ✅ Test 1 passed
### 入力:
```
10
20
30
40
50
20
30
40
50
60
30
40
50
60
70
```
### 出力:
```
英    数    国    理    社    平均点
1 番    10    20    30    40    50    30.0
2 番    20    30    40    50    60    40.0
3 番    30    40    50    60    70    50.0
平均点 20.0  30.0  40.0  50.0  60.0
``` 

# exer4-4.c
## code
```c

#include "stdio.h"

int main() {
    double a[10];
    a[0] = 1;
    a[1] = 2;
    // 2a_{n+2} - 3a_{n+1} + a_n = 0
    // 2a_{n} - 3a_{n-1} + a_{n-2} = 0
    // 2a_{n} = 3a_{n-1} - a_{n-2}
    // a_{n} = 1.5a_{n-1} - 0.5a_{n-2}
    for (int i = 2; i < 10; i++) {
        a[i] = 1.5 * a[i - 1] - 0.5 * a[i - 2];
    }
    printf("%f\n", a[9]);
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
2.996094
``` 

