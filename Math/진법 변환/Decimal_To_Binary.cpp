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
    
    // 반복 시 마다 1자리씩 늘리도록 i * 10
    for(int i = 1; number > 0; i *= 10) {
        
        // 홀수 짝수 인지 판단(0, 1)
        int binary = number % 2;
        
        // 2진수 자릿수 추가를 위하여 * i
        result += binary * i;
        
        // number를 2씩 나눔
        number /= 2;
    }
    
    return result;
}
