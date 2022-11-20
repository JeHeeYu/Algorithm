#include <iostream>

using namespace std;

int main()
{
    int A, B, N, result;
    
    // A, B, N 입력
    cin >> A >> B >> N;
    
    // N 번째 소숫점 까지 반복
    while(N--) {
      
        // A를 B로 나눠 몫을 구해 1자리 수로 만듦
        A %= B;
    
        // 1 이하일 경우 *10을 해서 소수점 몫만 출력
	// 1 이상일 경우 다음 소수점 자리 출력을 위해 반복
        A *= 10;
    
        // A를 B로 나눈 값, 즉 정답
        result = A / B;
    }
    
    cout << result << endl;
    

    return 0;
}
