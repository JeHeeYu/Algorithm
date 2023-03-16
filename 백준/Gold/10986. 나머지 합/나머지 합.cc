#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

 
    /*
        N : 수의 개수
        M : 나누어 떨어지는 값
        temp : 입력 받을 변수
        result : 정답, 즉 나누어 떨어지는 횟수
        v1 : 합 배열
        v2 : 합 배열을 M으로 나눈 배열
    */
    int N, M, temp;
    
    long result = 0;
    
    cin >> N >> M;
    
    vector<long> v1(N, 0);
    vector<long> v2(M, 0);
    
    cin >> v1[0];
    
    for(int i = 1; i < N; i++) {
        cin >> temp;
    
        // 합 배열 구하기    
        v1[i] = v1[i - 1] + temp;
    }
    
    for(int i = 0; i < N; i++) {
        temp = v1[i] % M;
        
        // M과 떨어지는 수이므로 1씩 증가
        if(temp == 0) {
            result++;
        }
        
        // 나머지가 같은 인덱수 개수 세기
        v2[temp]++;
    }
    
    for(int i = 0; i < M; i++) {
        if(v2[i] > 1) {
            // 나머지가 같은 인덱스 중 2개를 뽑아 경우의 수 더하기
            result += (v2[i] * (v2[i] - 1) / 2);
        }
    }
    
    cout << result << '\n';

    return 0;
}
