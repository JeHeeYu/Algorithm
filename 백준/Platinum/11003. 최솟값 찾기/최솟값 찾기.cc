#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, int> Node;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 숫자의 개수
        L : 최솟값을 구하는 범위
        dq : 데이터를 담을 덱
    */
    
    int N, L;
    deque<Node> dq;
    
    cin >> N >> L;
    
    for(int i = 0; i < N; i++) {
        int temp;
        
        cin >> temp;
        
        // 값이 들어올 때마다 현재 수보다 큰 값을 덱에서 제거
        while(dq.size() && dq.back().first > temp) {
            dq.pop_back();
        }
        
        dq.push_back(Node(temp, i));
        
        // 범위에서 벗어난 값은 덱에서 제거
        if(dq.front().second <= i - L) {
            dq.pop_front();
        }
        
        cout << dq.front().first << ' ';
    }

    return 0;
}
