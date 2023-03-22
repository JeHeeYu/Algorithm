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
        N : 데이터 개수
        v : 데이터를 저장할 배열
        max : 최대 값을 저장할 배열
    */
    
    int N, max = 0;
    
    cin >> N;
    vector<pair<int, int>> v(N);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    
    // 먼저 배열을 오름차순으로 정렬
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++) {
        // 정렬된 배열에서 최댓값을 찾아 swap이 일어나지 않는 부분을 찾음
        if(max < v[i].second - i) {
            max = v[i].second - i;
        }
    }
    
    // 인덱스의 값이므로 + 1 더함
    cout << max + 1;

    return 0;
}
