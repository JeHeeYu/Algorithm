#include <iostream>

using namespace std;

int ToDecimal(int number);

int main()
{
    int n;
    
    cout << "변환할 숫자 입력 : ";
    cin >> n;
    
    cout << "2진수" << n << "에서 10진수 " << ToDecimal(n) << "변환" << endl;

    return 0;
}

int ToDecimal(int number)
{ 
    int result = 0, n = 1;
    
    while(number > 0) {
        
        // 홀수일 경우 자릿수 값 확인하여 더하기
        if(number % 2 != 0) {
            
            result += n;
        }
        
        // 2진수 값을 더하기 위해 2씩 곱하기
        n *= 2;
        
        // 1자리씩 확인하기 위해 나누기
        number /= 10;
    }
    
    return result;
}
