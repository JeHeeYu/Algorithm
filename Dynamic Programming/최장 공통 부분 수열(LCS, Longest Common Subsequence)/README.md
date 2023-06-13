# 최장 공통 부분 수열

## 최장 공통 부분 수열(LCS, Longest Common Subsequence)
수학에서 수열(Sequence)은 어떤 물건이나 객체의 목록을 가리키는 용어이다.
<br>
그리고 이 수열(즉, 정렬되어 있는 객체의 목록)에서 일부 요소를 제거한 것을 부분 수열(Subsequence)라고 한다.
<br>
<br>
예를 들어 'GOOD MORNING'이 수열이라고 한다면, 'OMIG'는 이 수열의 부분 수열이라고 할 수 있다.
<br>
'OMIG'는 'GOOD MORNING' 에서 'G, O, D, O, R, N, N'을 제거한 결과이기 때문이다.
<br>
<br>
공통 부분 수열은 두 수열 사이에 공통적으로 존재하는 부분 수열을 말한다.
<br>
'GOOD MORNING'과 'GUTEN MORGEN'의 공통 부분 수열을 뽑으라면 'G', 'GO', 'GON', 'GMORN' 등이 나온다.
<br>
<br>
여기서 최장 공통 부분 수열은 여러 개의 공통 부분 수열 중 가장 긴 것을 말한다.
<br>
<br>
최장 공통 부분 수열(LSC) 알고리즘은 두 데이터를 비교할 때 아주 유용한 알고리즘이다.
<br>
두 텍스트 파일의 차이점을 찾아주는 UNIX의 diff 유틸리티도 이 알고리즘에 기반하여 만들어졌다.

<br>

## LCS 알고리즘
LCS 문제를 동적 계획벙브로 풀기 전에 먼저 이 문제가 최적 부분 구조로 이루어져 있는지 확인해야 한다.
<br>
이를 위해 X, Y 두 문자열이 있다고 가정하고 이 두 문자열을 매개 변수로 받아 이들 사이에서 나올 수 있는 LCS의 길이를 구하는 함수를 LCS_LENGTH() 라고 가정한다.
<br>
<br>
우선 i 또는 j 중 하나가 0이면 LCS_LENGTH(X(i), Y(j))의 결과는 0이 된다.
<br>
i 또는 j가 0이라면 두 문자열 중 하나의 길이가 0이라는 의미이고, 둘 중 하나의 길이가 0이면 공통 부분 수열이 존재하지 않기 때문이다.
<br>
<br>
두 번째 경우를 보면 x(i)와 y(j)가 같다면, 즉, X(i)와 Y(j)의 마지막 요소가 동일하다면 LCS_LENGTH(X(i), Y(j))는 LCS_LENGTH(X(i-1), Y(j-1)) + 1을 반환한다.
<br>
<br>
두 문자열의 동일한 마지막 요소는 당연히 LCS에 포함되므로 상수 1로 대체할 수 있기 때문이다.
<br>
<br>
그리고 마지막 요소를 뺀 두 문자열끼리의 LCS 길이를 구하여 상수 1과 더하면 원래 구하고자 했던 LCS 길이를 얻을 수 있다.
<br>
따라서 이 경우는 다음과 같은 식이 성립된다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/fe6a78d3-b73d-4620-a698-c53a09a914c0)


<br>

세 번째 경우를 보면, 두 문자열의 길이거 어느 한쪽도 0이 아니고 마지막 요소도 서로 다른 경우이다.
<br>
이 경우 LCS_LENGTH(X(i-1), Y(j))와 LCS_LENGTH(X(i), Y(j-1)) 중 큰 쪽이 LCS_LENGTH(X(i), Y(j))의 해이다.
<br>
<br>
이유는 두 문자열의 마지막 요소를 각각 x(i), y(j)라고 하면 두 요소끼리는 달라도 x(i)와 y(j-1)은 같을 수 있다.
<br>
또는 x(i-1)과 y(j)가 같을 수도 있다.
<br>
<br>
따라서 이 경우에는 LCS_LENGTH(X(i-1), Y(j))와 LCS_LENGTH(X(i), Y(j-1)) 중에서 큰 쪽이 LCS_LENGTH(X(i), Y(j))의 해가 되는 것이다.
<br>
<br>
이 세 가지 경우를 정리하면 다음과 같이 점화식을 만들 수 있다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/d26cc643-a694-4112-bf58-8251dddbbdcc)


<br>

이 점화식은 X와 Y의 LCS가 부분 LCS의 답으로부터 만들어지고 있음을 보여준다.
<br>
즉, 이 문제는 최적 부분 구조로 되어 있어서 동적 계획법으로 해를 구할 수 있다는 뜻이다.
<br>
<br>
한편 이 점화식은 다음과 같이 정리할 수도 있다.
<br>
이 점화식은 i x j의 테이블이 있다고 할 때 TABLE[i, j]는 LCS의 길이이며 TABLE의 각 요소는 TABLE[i, j]의 부분 문제들의 답을 담고 있다는 사실을 설명한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/f395cd51-f2d9-4c29-913c-8d238e62a895)



<br>

여기서 한 가지 주의해야 할 점이 있는데, 이 점화식에 나오는 i = 0, j = 0은 C 언어에서의 배열 인덱스 처럼 첫 번째 요소를 가리키는 것이 아니라는 사실이다.
<br>
i = 0 또는 j = 0은 그야말로 '아무것도 없음'을 나타낸다.
<br>
문자열 X의 첫 번째 요소는 i = 1, 문자열 Y의 첫 번째 요소는 j = 1이다.
<br>
<br>
아래는 앞의 점화식을 그대로 C언어 코드로 옮겨 작성한 LCS() 함수이다.
<br>
매개 변수는 모두 5개이며, 첫 번째와 두 번째 매개 변수는 문자열 X와 Y, 세 번째와 네 번째 매개변수는 테이블의 마지막 인덱스, 다섯 번째는 LCS 테이블이다.
<br>
<br>
마지막 매개 변수인 LCS 테이블의 크기는 i x j가 아닌 (i+1) x (j+1)이다.
<br>
이 테이블이 점화식의 테이블보다 행과 열이 1씩 긴 더 이유는 '아무것도 없는 행(i=0)과 열(j=0)을 표현하기 위해서다.

```
typedef struct structLCSTable
{
    int** data;
} LCSTable;

int LCS(char* x, char* y, int i, int j, LCSTable* table)
{
    if(i == 0 || j == 0) {
        table->data[i][j] = 0;
        return table->data[i][j];
    }
    else if(x[i - 1] == y[j - 1]) {
        table->data[i][j] = LCS(x, y, i - 1, j - 1, table) + 1;
        return table->data[i][j];
    }
    else {
        int a = LCS(x, y, i - 1, j, table);
        int b = LCS(x, y, i, j - 1, table);
        
        if(a > b) {
            table->data[i][j] = a;
        }
        else {
            table->data[i][j] = b;
        }
        
        return table->data[i][j];
    }
}
```

앞의 함수가 두 문자열 'GOOD MORNING' 및 'GUTEN MORGEN'으로부터 얻어낸 LCS 테이블의 결과는 다음과 같다.
<br>
이 테이블의 오른쪽 아래 모서리에 있는 마지막 요소에는 두 문자열 사이의 LCS 길이가 저장되어 있다.
<br>
<br>
그리고 테이블 안쪽에는 X와 Y의 부분 문자열에 대한 LCS의 길이들로 채워져 있다.
<br>
예를 들어 'GOOD MO'와 'GUTON MO' 사이에 존재하는 LCS의 길이는 다음 테이블에서 4('G', ' ', 'M', 'O')라는 사실을 알 수 있다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/8229ee39-346a-4018-9b5a-e9c11d10abf4)

<br>

이 LCS() 함수는 이렇게 작성하면 수행 시간이 지속적으로 증가한다.
<br>
LCS() 함수는 자기 자신을 재귀 호출하는 분기문 블록을 두 군데나 갖고 있기 때문이다.
<br>
<br>
그 중 마지막 블록은 LCS() 함수를 두 번 재귀 호출한다.
<br>
이런 구조의 재귀 호출은 수행 시간이 길어지는 단점이 있다.
<br>
하지만 동적 계획법을 이용한다면 이 알고리즘을 재구성하여 수행 시간을 O(nm) 수준으로 확 낮출 수 있다.

<br>

## 동적 계획법 기반 LCS 알고리즘
LCS 문제를 동적 계획법으로 풀 때 다음과 같이 동적 계획법 설계 절차를 따른다.
1. 문제를 부분 문제로 나눔
2. 가장 작은 부분 문제부터 해를 구한 뒤 테이블에 저장
3. 테이블에 저장된 부분 문제의 해를 이용하여 점차적으로 상위 부분 문제의 최적해를 구함

LCS 문제에서는 LCS 테이블의 각 요소가 각 부분 문제이다.
<br>
그리고 테이블의 오른쪽 아래 방향으로 내려가면서 나타나는 요소들이 부분 문제를 포함하는 상위 문제이닫.
<br>
가장 오른쪽 아래 모서리에 있는 요소가 전체 문제이다.
<br>
<br>
따라서 테이블의 왼쪽 위 모서리부터 시작해서 오른쪽 아래로 내려가면서 계산을 수행하면 가장 작은 문제부터 해를 구하고 이를 기반으로 상위 문제의 해를 구하게 된다.
<br>
<br>
마지막으로 오른쪽 아래 모서리에 이르게 디면 전체 LCS 길이의 해를 얻을 수 있다.
<br>
<br>
LCS의 점화식에 따르면 i = 0이거나 j = 0인 경우 Table[i, j] = 0이다.
<br>
따라서 모든 j에 대해서 Table[0, j]를 0으로 만들고 모든 i에 대해 Table[i, 0]을 0으로 만든다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/e9cf13e9-04b5-46a6-9551-991b639e02de)

<br>

그 다음부터는 테이블의 1번 행(두 번째 행)과 1번 열(두 번째 열)부터 LCS 길이를 구해 채워나가면 된다.
<br>
LCS 길이를 구하는 것은 점화식의 두 번째(X[i]와 Y[j]가 같은 경우)와 세 번째(i, j가 모두 0보다 크고 X[i]와 Y[j]가 다른 경우)를 이용하면 된다.
<br>
<br>
X[i]와 Y[j]가 같은 경우에는 Table[i, j]에 Table[i - 1, j - 1] + 1을 대입하면 되고, i와 j가 모두 0보다 크고 X[i]와 Y[j]가 서로 다를 때는 Tab;e[i - 1, j]나 Table[i, j - 1] 중 큰 값을 Table[i, j]에 대입하면 된다.
<br>
<br>
이렇게 테이블 왼쪽 위부터 오른쪽 아래까지 훑으면서 계산해나가면 X의 길이를 m, Y의 길이를 n이라고 했을 때 Table[m, n]을 구하는 데 최악의 경우라도 O(nm) 정도의 수행 시간이 소요된다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/a6139ed6-2fc4-40d8-b770-40f06193577e)


<br>

다음 코드는 동적 계획법으로 새롭게 작성한 LCS() 함수이다.

```
int LCS(char* x, char* y, int i, int j, LCSTable* table)
{
    int m = 0;
    int n = 0;

    for(m = 0; m <= i; m++) {
        table->data[m][0] = 0;
    }
    
    for(n = 0; n <= j; n++) {
        table->data[0][n] = 0;
    }
    
    for(m = 1; m <= i; m++) {
        for(n = 1; n <= j; n++) {
            if(x[m - 1] == y[n - 1]) {
                table->data[m][n] = table->data[m - 1][n - 1] + 1;
            }
            else {
                if(table->data[m][n - 1] >= table->data[m - 1][n]) {
                    table->data[m][n] = table->data[m][n - 1];
                }
                else {
                    table->data[m][n] = table->data[m - 1][n];
                }
            }
        }
    }
    
    return table->data[i][j];
}
```

이 함수를 이용하면 두 문자열의 LCS 길이를 O(nm) 시간 안에 알아낼 수 있게 되었다.
<br>
하지만 더 수정해야 할 부분이 있는데, LCS 길이를 구하려던 것이 아니라 LCS 자체를 구하려고 했던 것이다.
<br>
<br>
LCS는 LCS() 함수를 이용해서 만든 LCS 테이블에서 얻을 수 있다.
<br>
LCS 테이블의 오른쪽 아래 모서리부터 시작해서 왼쪽 위 모서리로 올라가면서 각 LCS 요소를 추적해내는 것이다.
<br>
<br>
LCS 테이블에서 LCS를 추적하는 알고리즘은 다음과 같다.
1. 오른쪽 아래 모소리 요소를 시작 셀로 지정하고, LCS의 요소를 담기 위한 리스트를 하나 준비
2. 현재 위치한 셀의 값이 왼쪽, 왼쪽 위, 위 셀의 값보다 크면 현재 셀의 값을 리스트 헤드에 삽입하고 왼쪽 위 셀로 이동
3. 현재 위치한 셀의 조건이 2번 과정에 해당하지 않으면 현재 셀의 값과 왼쪽 셀의 값이 같고 위 셀의 값보다 큰 경우 왼쪽으로 이동, 이동만 할 뿐이며 리스트에는 아무것도 넣지 않음
4. 2번 과정과 3번 과정 중 어느 경우에도 해당하지 않으면 위 셀로 이동하며, 리스트에 아무것도 넣지 않음
5. i = 0 또는 j = 0이 될 때까지 2 ~ 4번 과정 반복

다음 그림은 LCS() 함수를 만들어낸 LCS 테이블인데, LCS를 테이블 끝에서 추적해오는 예를 보여준다.

<br>


![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/7aef68a1-0379-4803-a715-af5d4459069f)


<br>

다음은 LCS 알고리즘을 구현한 LCS() 함수이다.

```
int LCS_TraceBack(char* x, char* y, int m, int n, LCSTable* table, char* lcs)
{
    if(m == 0 || n == 0) {
        return;
    }
    
    if(table->data[m][n] > table->data[m][n - 1]
        && table->data[m][n] > table->data[m - 1][n]
        && table->data[m][n] > table->data[m - 1][n - 1])  {
            char tempLCS[100];
            strcpy(tempLCS, lcs);
            sprintf(lcs, "%c%s", x[m - 1], tempLCS);
            
            LCS_TraceBack(x, y, m, n - 1, table, lcs);
        }
        else if(table->data[m][n] > table->data[m - 1][n]
                && table->data[m][n] == table->data[m][n - 1]){
            LCS_TraceBack(x, y, m, n - 1, table, lcs);
        }
        else {
            LCS_TraceBack(x, y, m - 1, n, table, lcs);
        }
}
```

### [LCS 예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Dynamic%20Programming/%EC%B5%9C%EC%9E%A5%20%EA%B3%B5%ED%86%B5%20%EB%B6%80%EB%B6%84%20%EC%88%98%EC%97%B4(LCS%2C%20Longest%20Common%20Subsequence)/Longest%20Common%20Subsequence.c)

### 실행 결과

```
    G U T E N   M O R G E N .  
  0 0 0 0 0 0 0 0 0 0 0 0 0 0 
G 0 1 1 1 1 1 1 1 1 1 1 1 1 1 
O 0 1 1 1 1 1 1 1 2 2 2 2 2 2 
O 0 1 1 1 1 1 1 1 2 2 2 2 2 2 
D 0 1 1 1 1 1 1 1 2 2 2 2 2 2 
  0 1 1 1 1 1 2 2 2 2 2 2 2 2 
M 0 1 1 1 1 1 2 3 3 3 3 3 3 3 
O 0 1 1 1 1 1 2 3 4 4 4 4 4 4 
R 0 1 1 1 1 1 2 3 4 5 5 5 5 5 
N 0 1 1 1 1 2 2 3 4 5 5 5 6 6 
I 0 1 1 1 1 2 2 3 4 5 5 5 6 6 
N 0 1 1 1 1 2 2 3 4 5 5 5 6 6 
G 0 1 1 1 1 2 2 3 4 5 6 6 6 6 
. 0 1 1 1 1 2 2 3 4 5 6 6 6 7 

LCS:G MORN." (Length:7)
```



