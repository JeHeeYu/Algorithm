## 소수(Prime Number)란
소수란 1보다 큰 자연수 중 1과 자기 자신만을 약수로 가지는 수를 말한다.
<br>
아래 표는 100 이하의 소수를 나타내는 표로, 1과 자기 자신 말고 약수가 존재하지 않는다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/202880829-883eb9ba-6b00-4994-b41c-052fe72b6233.JPG" width="550" height="450">
<br>
<br>

## 1. 모든 경우의 수를 전부 나누는 방법 O(n)
이 경우는 판단하는 수를 2부터 그 수까지 모두 나누는 방법이다.
<br>
모든 값을 하나하나 약수가 있는지 판단하는 알고리즘으로 구현은 쉽지만 시간 복잡도가 O(n)으로 가장 비효율적이다.
<pre>
bool PrimeNumber(int number)
{
    for(int i = 2; i < number; i++) {
        
        // 1개라도 나누어 떨어지면 약수가 존재하므로 false
        if(number % i == 0) {
            return false;
        }
    }
    
    // 나누어 떨어지는 값이 없으면 소수로 판단
    return true;
}
</pre>

## 2. 제곱근을 이용해 나누는 방법 O(√n)
이 경우 모든 경우의 수를 판단하는 방법보다 효율적인 알고리즘으로, 1/2 제곱만큼 검사 시간이 줄어든다.
<br>
제곱근이란 수학에서 어떤 수의 제곱근근 제곱하여 그 수가 되는 수를 가리키는 말이다.
<br>
쉽게 말해 약수가 존재하는 수라고 할 수 있다. (9제곱근은 3으로 3제곱은 9이다.)
<br>
<br>
제곱근을 이용하기 위해서 1번의 경우와 크게 다르지 않는데, 반복 조건을 sqrt(n)을 이용하면 된다.
<br>
sqrt 함수는 <cmath>에 존재하므로 #include <cmath>를 해주어야 한다.
<pre>
</pre>
#include <cmath>

bool PrimeNumber(int number)
{
    for(int i = 2; i < sqrt(number); i++) {
        
        // 1개라도 나누어 떨어지면 약수가 존재하므로 false
        if(number % i == 0) {
            return false;
        }
    }
    
    // 나누어 떨어지는 값이 없으면 소수로 판단
    return true;
}
