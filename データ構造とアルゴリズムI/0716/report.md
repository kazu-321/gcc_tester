# strc-1.c
## code
```c

#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score;
    char Grade;
};

int main() {
    struct data_struct data;
    data.No = 1;
    strcpy(data.Name, "James");
    data.Score = 78;
    data.Grade = 'B';
    printf(" No. |  Name  | Score | Grade |\n");
    printf("  %1d  | %5s  |  %2d   |   %c   |\n", data.No, data.Name, data.Score, data.Grade);
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
No. |  Name  | Score | Grade |
  1  | James  |  78   |   B   |
``` 

# strc-2.c
## code
```c

#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score;
    char Grade;
};

int main() {
    struct data_struct data[4] = {
        {1, "James", 78, 'B'},
        {2, "John", 92, 'A'},
        {3, "Mary", 85, 'A'},
        {4, "Susan", 78, 'B'}
    };

    printf(" No. |  Name  | Score | Grade |\n");
    for (int i = 0; i < 4; i++) {
        printf("  %1d  | %5s  |  %2d   |   %c   |\n", data[i].No, data[i].Name, data[i].Score, data[i].Grade);
    }
    return 0;
}
```
## result
## ❌ Test 0 failed
### 入力:
```

```
### 出力:
```
No. |  Name  | Score | Grade |
  1  | James  |  78   |   B   |
  2  |  John  |  92   |   A   |
  3  |  Mary  |  85   |   A   |
  4  | Susan  |  78   |   B   |
```
### 期待:
```
No. |  Name  | Score | Grade |
  1  | James  |  78   |   B   |
  2  |  John  |  92   |   A   |
  3  |  Mary  |  85   |   A   |
  4  | Susan  |  78   |   B   |
``` 

# strc-3.c
## code
```c

#include <stdio.h>
#include <string.h>

struct data_struct {
    int No;
    char Name[128];
    int Score_math;
    int Score_english;
    float Average;
};

int main() {
    struct data_struct data[6] = {
        {1, "James", 78, 67, 0.0},
        {2, "John", 92, 82, 0.0},
        {3, "Mary", 85, 79, 0.0},
        {4, "Susan", 78, 81, 0.0},
        {5, "Brian", 72, 82, 0.0},
        {6, "Ruth", 84, 77, 0.0}
    };
    for (int i = 0; i < 6; i++) {
        data[i].Average = (data[i].Score_math + data[i].Score_english) / 2.0;
    }
    printf(" No. |  Name  | Math. | Eng. | Ave. |\n");
    for (int i = 0; i < 6; i++) {
        printf("  %1d  | %5s  |  %2d   |  %2d  | %.1f |\n", 
               data[i].No, data[i].Name, 
               data[i].Score_math, data[i].Score_english, 
               data[i].Average);
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
No. |  Name  | Math. | Eng. | Ave. |
  1  | James  |  78   |  67  | 72.5 |
  2  |  John  |  92   |  82  | 87.0 |
  3  |  Mary  |  85   |  79  | 82.0 |
  4  | Susan  |  78   |  81  | 79.5 |
  5  | Brian  |  72   |  82  | 77.0 |
  6  |  Ruth  |  84   |  77  | 80.5 |
``` 

# strc-4.c
## code
```c

#include <stdio.h>
#include <string.h>
#include <math.h>

struct data_struct {
    char Name[128];
    int Score;
};

int main() {
    FILE *fp = fopen("データ構造とアルゴリズムI/0716/data.txt", "r");
    if (fp == NULL) {
        printf("Failed to open data.txt\n");
        return 1;
    }

    struct data_struct data[50];
    int i = 0;
    int sigma_score = 0;

    char tmp_name[128];
    int tmp_score;
    while (fscanf(fp, "%s %d", tmp_name, &tmp_score) == 2) {
        strcpy(data[i].Name, tmp_name);
        data[i].Score = tmp_score;
        sigma_score += tmp_score;
        i++;
    }

    fclose(fp);

    float average_score = (float)sigma_score / i;
    printf("Average Score: %.2f\n", average_score);

    float variance = 0.0f;
    for (int j = 0; j < i; j++) {
        float diff = data[j].Score - average_score;
        variance += diff * diff;
    }
    variance /= i;
    float standard_deviation = sqrt(variance);
    printf("Standard Deviation: %.2f\n", standard_deviation);

    printf("Students with scores 85 or above:\n");
    printf("  Name  | Score |\n");
    int count = 0;
    for (int j = 0; j < i; j++) {
        if (data[j].Score >= 85) {
            printf("%7s |  %d   |\n", data[j].Name, data[j].Score);
            count++;
        }
    }
    printf("Total students with scores 85 or above: %d\n", count);
}
```
## result
## ✅ Test 0 passed
### 入力:
```

```
### 出力:
```
Average Score: 78.54
Standard Deviation: 6.97
Students with scores 85 or above:
  Name  | Score |
 George |  93   |
  Jacob |  85   |
   Mark |  85   |
   Mary |  97   |
  Betty |  90   |
  Karen |  86   |
  Smith |  88   |
    Ken |  86   |
 Sharon |  89   |
  Laura |  98   |
  Sarah |  87   |
Total students with scores 85 or above: 11
``` 

