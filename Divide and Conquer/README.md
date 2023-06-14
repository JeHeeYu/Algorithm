# 분할 정복 정리 내용

## 분할 정복 알고리즘 개념
분할 정복 알고리즘은 문제를 더 이상 나눌 수 없을 때까지 나누고, 이렇게 나뉜 문제들을 각각 풀어 결국 전체 문제의 답을 얻는 기법이다.
<br>
분할 정복 알고리즘의 핵심은 문제를 잘게 나누는 것이다.
<br>
문제를 쪼개는 방법에는 정해진 규칙이나 공식은 없다.
<br>
<br>
하지만 분할 정복 알고리즘을 설계하는 대강의 요령은 있는데, 다음과 같다.
- 분할(Divide) : 문제가 분할 가능한 경우 2개 이상의 하위 문제로 나눔
- 정복(Conquer) : 하위 문제가 여전히 분할 가능한 상태라면 하위 집합에 대해 1단계를 수행, 그렇지 않다면 하위 문제를 품
- 결합(Combine) : 2단계를 통해 구한 답을 취합

분할 정복 기법으로 문제를 나눌 때 생기는 각 하위 문제는 완전히 독립적이다.
<br>
다시 말해 큰 문제에서 분할된 작은 문제들은 여러 프로세스, 네트워크상의 여러 컴퓨터에 의해 병렬 처리로 해결 가능하다는 의미이다.
<br>
<br>
하지만 분할 정복이 무조건 장점만 갖고 있는 것은 아니다.
<br>
분할 정복 알고리즘을 구현할 때 재귀 호출이 많이 사용된다.
<br>
<br>
이 때문에 문제를 잘게 나눔으로써 얻어진 알고리즘의 효율성을 재구 호출 비용이 깎아내리기도 한다.

<br>

## 병합 정렬(Merge Sort)
병합 정렬은 퀵 정렬과 같이 분할 정복에 기반한 정렬 알고리즘이다.

## 병합 정렬 동작 방식
병합 정렬 알고리즘은 요약하면 '나누고 합치기' 작업이다.
<br>
구체적으로 다음과 같은 순서로 동작한다.
1. 정렬할 데이터를 반으로 나눔
2. 나뉜 하위 데이터의 크기가 2 이상이면 이 하위 데이터에 대해 1단계 반복
3. 동일 데이터에서 나뉜 하위 데이터 둘을 병합하여 원래대로 하나의 데이터를 만들되, 병합할 때 데이터의 원소는 정렬 기준에 따라 정렬
4. 데이터가 원래대로 모두 하나가 될 때까지 3단계 반복

이 알고리즘을 구현할 때 두 하위 데이터를 병합하는 부분에 관심을 두어야 한다.
<br>
병합 정렬의 성능을 좌우하는 부분이기 때문이다.
<br>
<br>
예제를 들기 위해 아래와 같이 정렬되지 않은 데이터가 있다고 가정한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/d2df354e-05aa-4f64-834f-ee71a9995333)


<br>

병합 정렬을 하기 위해 먼저 원래의 데이터를 반으로 나누어야 한다.
<br>
그렇게 하려면 알고리즘의 1 ~ 2단계를 반복해야 한다.
<br>
<br>
다음 그림은 원본 데이터를 하위 데이터로 나눠가는 과정을 보여준 그림이다.
<br>
원본 데이터 및 각 하위 데이터에서 보라색으로 표시된 요소는 데이터 중간에 위치한 기준점을 의미한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/a5f1aae8-3ca6-43d4-bef7-6f3d7e89e753)


<br>

'분할' 단계를 끝냈으니 이제 '정복'을 할 차례이다.
<br>
알고리즘의 3 ~ 4단꼐를 반복해서 수행하되, 나뉜 하위 데이터들이 다시 모두 하나가 됐을 때 알고리즘을 종료한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/2de4126f-01fa-4a14-a447-478ddfa944ae)

<br>

즉, 데이터를 나누고 정렬하면서 합친다 라는 과정이다.
<br>
원본 데이터를 나눈 다음 조각난 각 하위 데이터를 정렬하면서 병하뱋나가면 결국 완전히 정렬된 하나의 데이터를 얻을 수 있다.
<br>
<br>
여기서 추가로 알아야 할 부분이 '정렬'을 수행하는 부분이다.
<br>
그것도 두 데이터를 하나로 합치면서 하는 정렬을 알아야 한다.
<br>
<br>
정렬을 수행하는 과정은 다음과 같이 3단계로 이루어진다.
1. 두 데이터를 합한 것만큼 비어 있는 데이터(공간)를 마련
2. 두 데이터의 첫 번째 요소들을 비교하여 작은 요소를 새 데이터에 추가<br>그리고 새 데이터에 추가된 요소는 원래의 양쪽 데이터에서 삭제
3. 양쪽 데이터가 빌 때까지 2단계 반복

이해를 돕기 위해 아래와 같이 데이터 A와 B가 있고, 같은 크기의 빈 데이터 C가 있다.
<br>
여기서 A와B를 병합해서 C에 채워넣는다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/d47d4888-a954-4f96-898f-b8285fce00d3)

<br>

먼저 A와 B의 첫 번째 요소끼리 비교를 수행한다.
<br>
A의 첫 번째 요소는 1, B의 첫 번째 요소는 2이므로 A의 것이 더 작으므로 C에 1을 입력하고 A에서 1을 삭제한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/e06661a5-b506-4395-b49d-2dfa09219130)

<br>

다음으로 A의 4와 B의 2를 비교한다.
<br>
2가 작으니 2를 B에서 삭제하고 C에 입력한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/bc6f8ecc-b47f-4aa4-a3b3-29ca4565d5c3)

<br>

이번에는 A의 4와 B의 3을 비교한다.
<br>
3이 작으니 이를 B에서 제거하고 C에 입력한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/fb501df7-ae75-4cf8-9f46-22063f23f236)

<br>

다시 A의 4와 B의 7을 비교한다.
<br>
C에 4를 입력하고 더 작은 A의 4는 A에서 삭제한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/8ea57d39-dd4e-4b11-b823-b5ce609a8271)

<br>

이와 같이 데이터 A와 B에 남은 첫 번째 요소를 비교하고 C에 옮겨 넣는 일을 계속 하다보면 B에 9 하나만 남게 된다.
<br>
A에는 비교할 데이터가 남아 있지 않으므로 이를 C에 입력하고 B에서 삭제한다.
<br>
<br>
이로써 A와 B가 모두 비게 되었고 C는 정렬된 데이터가 되었다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/08ea2082-7a4a-41d0-acc6-54208c1ab462)

<br>

## 병합 정렬 알고리즘 구현
분할 정복에 기반하여 설계된 알고리즘은 재귀 호출을 이용해 쉽게 구현할 수 있다.
<br>
병합 정렬도 재귀 호출을 이용하여 나누고 병합하는 과정을 구현할 수 있다.
<br>
<br>
병합 정렬 알고리즘을 구현하는 MergeSort() 함수는 크게 세 가지 작업을 수행한다.
<br>
첫 번째로 데이터를 반으로 나누고, 두 번째로 반으로 나눈 데이터를 매개 변수로 삼아 스스로를 재귀 호출하고, 마지막으로 둘로 나눈 데이터를 다시 병합한다.

```
void MergeSort(int dataSet[], int startIndex, int endIndex)
{
    int middleIndex;
    
    if(endIndex - startIndex < 1) {
        return;
    }
    
    middleIndex = (startIndex + endIndex) / 2;
    
    MergeSort(dataSet, startIndex, middleIndex);
    MergeSort(dataSet, middleIndex + 1, endIndex);
    Merge(dataSet, startIndex, middleIndex, endIndex);
}
```

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Divide%20and%20Conquer/Mergesort.cpp)

### 실행 결과

```
1 2 3 4 5 6 12 34 117 334
```

<br>

## 거듭 제곱(Exponenitation)
거듭 제곱은 컴퓨팅에서 자주 사용되는 연산 중 하나이다.
<br>
하지만 일반 산술 연산과 달리 의외로 수행 시간이 오래 걸리는데, 이 문제를 분할 정복으로 해결할 수 있다.

## 거듭 제곱 계산법
예를 들어 C^2을 계산하기 위해서는 다음과 같이 C 자신을 두 번 곱해야 한다.

```
C^2 = C * C
```

또한 C^3을 계산하기 위해 다음과 같이 C 자신을 세 번 곱해야 한다.

```
C^3 = C * C * C
```

그리고 C^n을 계산하려면 다음과 같이 C 자신을 n번 곱해야 한다.

```
C^n = C * C * ... * C
```

<br>

이것을 C++ 언어 코드로 바꾸면 다음과 같다.

```
int Power(int base, int exponent)
{
    int result = 1; // C^0 = 1
    
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    return result;
}
```

매개 변수 exponent(지수)의 크기만큼 곱셈을 수행하므로 이 알고리즘은 exponent에 대해 O(n)의 수행 시간을 소요한다는 사실을 알 수 있다.
<br>
이보다 더 좋은 성능을 얻을 수 있는데, 그건 거듭 제곱을 이용하는 방법이다.
<br>
<br>
예를 들어 C^8은 C 자기 자신을 7번 곱해야 한다.
<br>
하지만 C^8을 구할 때 C를 7번 곱하지 않고 C^2을 구한 뒤 제곱을 두 번더 반복하면 값을 얻을 수 있다.
<br>
결국 세 번의 곱셈만 수행함으로써 같은 결과를 얻을 수 있는 것이다.
<br>
<br>
이 원리에 의하면 C^64를 구할 때도 여덟 번만 곱셈을 수행하면 된다.
<br>
하지만 이 방법을 모든 제곱 연산에 적용할 수는 없다.
<br>
<br>
예를 들어 지수가 홀수인 경우도 있기 때문이다.
<br>
이렇게 지수를 반으로 나눠가는 알고리즘의 수행 시간은 O(log^2n)이다.
<br>
처음에 O(n)이었던 버전에 비하면 성능이 비약적으로 향상되었다.

<br>

## 거듭 제곱 계산 알고리즘 구현
먼저 거듭 제곱 연산의 결과는 아주 크기 때문에 이를 담을만한 크기의 자료형이 필요하다.
<br>
결과를 담는 자료형으로는 unsigned long을 사용한다.

```
typedef unsigned long ULONG; // 64bit
```

다음은 거듭 제곱을 수행하는 Power() 함수이다.

```
ULONG Power(int base, int exponent)
{
    if(exponent == 1) {
        return base;
    }
    else if(base == 0) {
        return 1;
    }
    
    if(exponent % 2 == 0) {
        ULONG newBase = Power(base, exponent / 2);
        return newBase * newBase;
    }
    else {
        ULONG newBase = Power(base, (exponent - 1) / 2);
        return (newBase * newBase) * base;
    }
}
```

<br>

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Divide%20and%20Conquer/Exponenitation.cpp)

### 실행 결과

```
2^30 = 1073741824
```

<br>

## 분할 정복 기반 피보나치 수 구하기
피보나치 수열의 정의가 다음과 같으므로 피보나치 수열을 찾는 코드를 작성하는 일은 어렵지 않다.
<br>
재귀 방정식을 그대로 코드로 옮길 수 있기 때문이다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/31b4bc37-858a-44e9-822f-7842cd7c6295)


<br>

```
ULONG Fibonacci(int n)
{
    if(n == 0) {
        return 0;
    }
    
    if(n == 1 || n == 2) {
        return 1;
    }
    
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```

하지만 이 코드의 가장 큰 문제점은 이 코드는 분할 정복(Divide and Conquer)이 아닌 단순 연속 정복(Double and Conquer) 방식으로 피보나치 수를 구한다는 점이다.
<br>
<br>
예를 들어 Fibonacci(n)을 호출하면  2개의 재귀 호출 Fibonacci(n - 1), Fibonacci(n - 2)가 발생한다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/a9dc42d0-aae6-4ad7-a3f3-f363da3857b8)

<br>

Fibonacci(n - 1)은 Fibonacci(n - 2)와 Fibonacci(n - 3)의 호출을 생성하고 Fibonacci(n - 2)는 Fibonacci(n - 3)과 Fibonacci(n - 4)의 호출을 생성한다.
<br>
<br>
따라서 두 번째 단계에서 Fibonacci() 호출이 4개로 늘어난다.

<br>

![image](https://github.com/JeHeeYu/Book-Reviews/assets/87363461/81996d7b-2b35-416d-a22d-378a571085db)

<br>

위 그림을 보면 Fibonacci(n)에 의해 생성된 Fibonacci(n - 2) 호출이 Fibonacci(n - 1)에 의해서도 완전히 새롭게 생성되는 것을 알 수 있다.
<br>
또한 Fibonacci(n - 1)에 의해 생성된 Fibonacci(n - 3) 호출이 Fibonacci(n - 2)에 의해서도 똑같이 생성된다.
<br>
<br>
그 다음 단계를 하면 모두 8개의 Fibonacci() 함수 호출이 생기며 이 반복은 n이 0으로 될 때까지 계속 반복된다.
<br>
<br>
즉, 상당히 비효율적인 수행 시간을 필요로 한다.

<br>

## 분할 정복으로 피보나치 수 구현
피보나치 수도 데이터의 용량이 크기 때문에 unsigned long 자료형을 사용한다.

```
typedef unsigned long ULONG;
```

그리고 ULONG 형식의 2차원 배열을 갖는 Matrix2*2 구조체를 다음과 같이 선언한다.

```
typedef struct tagMatrix2x2
{
    ULONG data[2][2];
} Matrix2x2;
```

그리고 피보나치 수를 구하는 Fibonacci() 함수를 구현한다.
<br>
이 함수는 몇 번째 피보나치 수를 구할 것인지 나타내는 n을 매개 변수로 받고  ULONG 형식으로 피보나치 수를 반환한다.
<br>
<br>
이 피보나치 수는 행렬이므로 이 행렬을 n 제곱하는 Matrix2x2Poewr() 함수를 호출한다.

```
ULONG Fibonacci(int n)
{
    Matrix2x2 a;
    
    // 행렬 초기화
    a.data[0][0] = 1; 
    a.data[0][1] = 1;
    a.data[1][0] = 1; 
    a.data[1][1] = 0;

    // 행렬 제곱 계산
    a = Matrix2x2Power(a, n);

    return a.data[0][1];
}

Matrix2x2 Matrix2x2Power(Matrix2x2 a, int n)
{

    if(n > 1)  {
        a = Matrix2x2Power(a, n / 2);
        a = Matrix2x2Multiply(a, a);

        if(n & 1)  
        {
            Matrix2x2 b;    
            b.data[0][0] = 1;
            b.data[0][1] = 1;
            b.data[1][0] = 1;
            b.data[1][1] = 0;

            a = Matrix2x2Multiply(a, b);
        }
    }
              
    return a;
}
```

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Divide%20and%20Conquer/Fibonacci.cpp)

### 실행 결과

```
Fibonacci(46) = 1836311903
```
