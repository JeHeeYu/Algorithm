#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    /*
        N : 수의 개수
        result : 정답을 담을 변수
        v : N개의 수 값을 받을 배열
        sum : 합 배열을 구할 배열
    */
    int N, result = 0;
    
    cin >> N;
    
    vector<int> v(N, 0);
    vector<int> sum(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    // 가장 적은 시간을 구하기 위해 오름차순 정렬
    sort(v.begin(), v.end());
    
    sum[0] = v[0];
    
    // 합 배열 구함
    for(int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + v[i];
    }
    
    for(int i = 0; i < N; i++) {
        result += sum[i];
    }
    
    cout << result;

    return 0;
}
