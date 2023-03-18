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
        N : 수의 개수
        v : 수의 개수를 담을 배열
        result : 좋은 수 개수
    */
    
    int N, result = 0;
    
    cin >> N;
    
    vector<int> v(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < N; i++) {
        long good = v[i];
        int start = 0;
        int end = N - 1;
        
        while(start < end) {
            // 
            if(v[start] + v[end] == good) {
                // 서로 다른 수인지 체크해야 함
                // 좋은 수이므로 반복문 탈출, 카운트 증가
                if(start != i && end != i) {
                    result++;
                    break;
                }
                else if(start == i) {
                    start++;
                }
                else if(end == i) {
                    end--;
                }
            }
            else if(v[start] + v[end] < good) {
                start++;
            }
            else {
                end --;
            }
        }
    }
    
    cout << result << '\n';

    return 0;
}
