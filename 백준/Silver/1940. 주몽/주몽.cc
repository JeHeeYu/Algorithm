#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 재료의 개수
        M : 갑옷을 만드는데 필요한 재료 수
        v : 재료의 개수를 담을 배열
        start : 배열에서 재료를 검색할 시작 포인터 인덱스
        end : 배열에서 재료를 검색할 끝 포인터 인덱스
        result : 갑옷을 만들 수 있는 개수
    */
    
    int N, M;
    
    cin >> N >> M;
    
    vector<int> v(N, 0);
    
    int start = 0, end = N - 1, result = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    while(end > start) {
        // 갑옷을 만들 수 있을 때
        if(v[start] + v[end] == M) {
            result++;
            start++;
            end--;
        }
        // M보다 값이 크므로 끝 인덱스의 값을 낮춰야 함
        else if(v[start] + v[end] > M) {
            end--;
        }
        // M보다 값이 낮으므로 시작 인덱스 값을 높여야 함
        else {
            start++;
        }
    }
    
    cout << result << '\n';

    return 0;
}
