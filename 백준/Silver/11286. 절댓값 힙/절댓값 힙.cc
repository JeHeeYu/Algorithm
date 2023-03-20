#include <iostream>
#include <queue>

using namespace std;

struct compare 
{
    bool operator()(int a, int b) {
        int first = abs(a);
        int second = abs(b);
        
        // 절댓값이 같을 경우 음수 우선
        if(first == second) {
            return a > b;
        }
        // 절댓값을 기준으로 정렬
        else {
            return first > second;
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 연산의 개수
        q : 값을 저장할 우선순위 큐
    */
    int N;
    
    cin >> N;
    
    priority_queue<int, vector<int>, compare> q;
    
    for(int i = 0; i < N; i++) {
        int temp;
        
        cin >> temp;
        
        // x가 0일 경우
        if(temp == 0) {
            // 배열이 비어 있으므로 0 출력
            if(q.empty()) {
                cout << "0\n";
            }
            // 배열에서 절댓값이 가장 작은 경우 출력
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        // x가 0이 아닐 경우 값을 넣는 연산이므로 푸쉬 연산
        else {
            q.push(temp);
        }
    }

    return 0;
}
