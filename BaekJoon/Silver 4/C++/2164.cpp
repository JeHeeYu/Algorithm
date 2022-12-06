#include <iostream>
#include <queue>

using namespace std;


int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    queue<int> q;
    
    cin >> N;
    
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }
    
    while(q.size() > 1) {
        q.pop();        // 처음 카드 버림 
        q.push(q.front());  // 맨 앞의 카드 값을 뒤로 보냄
        q.pop();  // 다시 카드 버림
    }
    
    cout << q.front();

    return 0;
}
