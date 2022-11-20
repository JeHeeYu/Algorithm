#include <iostream>
#include <cmath>

using namespace std;

bool PrimeNumber(int number);

int main()
{
    int n;
    
    cin >> n;
    
    cout << n << " 이하 소수" << endl;
    
    PrimeNumber(n);

    return 0;
}

bool PrimeNumber(int number)
{
    // n이하(포함) 이므로 + 1 까지 동적 할당
    bool *isPrime = new bool[number + 1];
    
    // 먼저 모든 값을 true로 초기화
    for(int i = 0; i < number; i++) {
        isPrime[i] = true;
    }
    
    for(int i = 2; i < number; i++) {
        // 소수일 경우 해당 수를 제외한 배수들을 모두 제외
        if(isPrime[i] == true) {
            // 소수 출력
            cout << i << endl;
            
            // 소수 일 경우 *2 씩 하여 모든  값을 false로 할당
            for(int j = i * 2; j <= number; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
