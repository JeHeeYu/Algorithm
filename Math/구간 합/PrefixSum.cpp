#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 수의 개수
        M : 합을 구해야 하는 횟수
        i : 합을 구해야 하는 시작 범위
        j : 합을 구해야 하는 끝 범위
        temp : 임시로 값을 입력 받을 변수
    */
    int N, M, i, j, temp;
    
    cin >> N >> M;
    
    int S[100001] = { 0 };
    
    // 수의 개수만큼 입력 받음
    for(int k = 1; k <= N; k++) {
        cin >> temp;
        
        // 구간 합 구하기
        S[k] = S[k - 1] + temp;
    }
    
    for(int k = 0; k < M; k++) {
        cin >> i >> j;
        
        cout << S[j] - S[i - 1] << "\n";
    }

    return 0;
}
