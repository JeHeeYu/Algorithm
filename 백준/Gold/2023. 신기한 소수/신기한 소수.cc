#include <iostream>

using namespace std;

void DFS(int number, int jarisu);
bool isPrime(int num);
static int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 자리 수
    */
    
    cin >> N;
    
    // 2, 3, 5, 7을 시작 수로 지정
    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);

    return 0;
}

void DFS(int number, int jarisu)
{
    if(jarisu == N) {
        // 소수이면 출력
        if(isPrime(number)) {
            cout << number << "\n";
        }
        return;
    }
    
    for(int i = 1; i < 10; i++) {
        // 짝수이면 더 이상 탐색할 필요 없음
        if(i % 2 == 0) {
            continue;
        }
        
        // 소수이면 재귀로 자릿수를 늘림
        if(isPrime(number * 10 + i)) {
            DFS(number * 10 + i, jarisu + 1);
        }
    }
}

bool isPrime(int num)
{
    for(int i = 2; i <= num / 2; i++) {
        // 짝수이므로 false
        if(num % i == 0) {
            return false;
        }
    }
    
    return true;
}