#include <iostream>
#include <cmath>

using namespace std;

bool PrimeNumber(int number);

int main()
{
    int n;
    
    cin >> n;
    
    cout << n << " 이하 소수" << endl;
    
    for(int i = 2; i <= n; i++) {
        if(PrimeNumber(i) == true) {
            cout << i << endl;
        }
    }
    
    return 0;
}

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
