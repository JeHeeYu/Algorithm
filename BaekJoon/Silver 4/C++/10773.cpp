#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    int K, n, result = 0;
    
    cin >> K;
    
    for(int i = 0; i < K; i++) {
        cin >> n;
        
        if(n == 0) {
            s.pop();
        }
        else {
            s.push(n);
        }
        
    }
    
    n = s.size();
    
    for(int i = 0; i < n; i++) {
        result += s.top();
        s.pop();
        
    }
    cout << result << endl;

    return 0;
}
