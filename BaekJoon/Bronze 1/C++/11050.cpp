#include <iostream>

using namespace std;

int Factorial(int num);

int main() {
    int N, K;
    
    cin >> N >> K;

    cout << Factorial(N) / (Factorial(K) * Factorial(N - K));

    return 0;
}

int Factorial(int num)
{
    if(num <= 1) {
        return 1;
    }
    else {
        return num * Factorial(num - 1);
    }
}
