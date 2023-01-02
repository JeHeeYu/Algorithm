#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

int main()
{
    int N, number;
    
    vector<int> v;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> number;
        
        v.push_back(number);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
