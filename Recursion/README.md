# 재귀함수(Recursion)

## 재귀(Recursive)란
어떤 사건이 자기 자신을 포함하고 다시 자기 자신을 사용하여 정의될 때 재귀적 이라고 한다.
<br>
쉽게 말해서 자기 자신을 포함한 것이라고 쉽게 생각할 수 있다.
<br>
<br>
프로그래밍에서 재귀란 하나의 함수에서 자신을 다시 호출하여 작업을 수행하는 방식으로 주어진 문제를 푸는 방법을 말한다.
<br>
재귀를 효과적으로 사용하면 프로그램을 간결하게 작성할 수 있다.
<br>
<br>
재귀적 정의에 의해 무한으로 존재하는 자연수를 아래의 두 조건으로 정의할 수 있다.
<ul>
  <li>1은 자연수이다.</li>
  <li>자연수 n의 바로 다음 수도 자연수이다.</li>
</ul>

## 팩토리얼(Factorial)
팩토리얼이란 한글로 계승 또는 순차곱셈이라고 하며, 1에서 시작하여 어떤 범위에 있는 모든 정수를 곱하는 것을 의미한다.
<br>
팩토리얼 예제는 재귀함수의 예제로 많이 사용한다.
<pre>
#include <stdio.h>

int Factorial(int n);

int main()
{
    int n;
    printf("정수를 입력하세요 : ");
    scanf("%d", &n);
    
    printf("%d의 Factorial 값은 %d 입니다.\n", n, Factorial(n));
    
    return 0;
}

int Factorial(int n)
{
    if(n > 0) {
        return n * Factorial(n - 1);
    }
    else {
        // 마지막 호출일 때
        return 1;
    }
}
</pre>
팩토리얼의 표기식은 숫자 뒤에 !를 붙여 표시한다.
<br>
예를 들어, 10의 팩토리얼인 10!은 10 * 9!로 구할 수 있고, 표시할 수 있다.

## 3을 매개변수로 받은 팩토리얼 함수 호출 과정
A : Factorial(3)을 실행하면 3 * Factorial(2)를 반환하는데, 이 값을 구하기 위해 다시 2를 매개변수로 주고 Factorial 함수를 호출한다.
<br>
<br>
B : 호출된 함수는 매개변수 n에 2를 전달받고, 다시 2 * Factorial(1)을 수행하기 위해 Factorial 함수를 호출한다.
<br>
<br>
C : 다시 호출된 Factorial 함수는 매개변수 n에 1을 전달받고, 1 * Factorial(0)을 수행하기 위해 Factorial 함수를 호출한다.
<br>
<br>
D : 마지막으로 호출된 Factorial 함수는 매개변수 n에 전달받은 값이 0이므로 1을 반환한다.
<br>
<br>
마지막 함수 호출 후, 다시 C - B - A 순서로 역순으로 실행된다.
