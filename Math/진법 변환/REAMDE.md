# 10진수에서 2진수 변환

## 라이브러리 사용하지 않고 구현

<pre>
#include <iostream>

using namespace std;

int ToBinary(int number);

int main()
{
    int n;
    
    cout << "변환할 숫자 입력 : ";
    cin >> n;
    
    cout << "10진수" << n << "에서 2진수 " << ToBinary(n) << "변환" << endl;

    return 0;
}

int ToBinary(int number)
{
    int result = 0;
    
    for(int i = 1; number > 0; i *= 10) {
        int binary = number % 2;
        result += binary * i;
        number /= 2;
    }
    
    return result;
}
</pre>
