#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, K, num;
    vector<int> v;
    
    cin >> N >> K;
    
    for(int i = 0; i < N; i++) {
        cin >> num;
        
        v.push_back(num);
    }
    
    sort(v.begin(), v.end());
    
    cout << v[N - K] << endl;

    return 0;
}
