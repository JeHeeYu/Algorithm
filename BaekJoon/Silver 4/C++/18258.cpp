#include <iostream>
#include <queue>

using namespace std;

int main()
{
    
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, number;
    
    string str;
    
    queue<int> q;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        
        if(str == "push") {
            cin >> number;
            q.push(number);
        }
        else if(str == "pop") {
            if(q.size() == 0) {
                cout << -1 << '\n';
            }
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(str == "size") {
            cout << q.size() << '\n';
        }
        else if(str == "empty") {
            cout << q.empty() << '\n';
        }
        else if(str == "front") {
            if(q.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << q.front() << '\n';
            }
        }
        else {
            if(q.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << q.back() << '\n';
            }
        }
    }

    return 0;
}
