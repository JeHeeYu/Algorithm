#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 수의 개수
        v : N개의 수를 입력 받을 배열
        result : 정답을 저장할 배열
        s : 배열의 인덱스를 관리할 스택
    */
    int N;
    
    cin >> N;
    
    vector<int> v(N, 0);
    vector<int> result(N, 0);
    
    stack<int> s;
    
    // 초기 인덱스 관리를 위해 스택에 0 푸쉬
    s.push(0);
    
    // N개의 수 입력 받음
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for(int i = 1; i < N; i++) {
        // 스택이 비지 않았으면서 입력 받은 배열에서 이전 인덱스와 현재 인덱스 값 비교
        while(s.empty() == false && v[s.top()] < v[i]) {
            // 예를 들어 v[0]보다 v[1]이 더 크면 오큰수므로 결과 배열에 오큰수 저장
            result[s.top()] = v[i];
            s.pop();
        }
        
        // 다음 인덱스 확인을 위해 i 값 푸쉬
        s.push(i);
    }
    
    // 맨 마지막 수는 오큰수가 없으므로 -1 푸쉬
    while(s.empty() == false) {
        result[s.top()] = -1;
        s.pop();
    }
    
    for(int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}
