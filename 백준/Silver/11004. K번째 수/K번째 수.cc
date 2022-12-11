#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N, K, A;
    vector<int> v;
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> A;
        
        v.push_back(A);
    }
    
    sort(v.begin(), v.end());
    cout << v[K - 1] << '\n';
    

    return 0;
}