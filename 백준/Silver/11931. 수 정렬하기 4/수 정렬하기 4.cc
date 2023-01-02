#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// vector begin이 end보다 클 경우 true
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
    
    // compare 함수를 이용해서 역순으로 정렬하도록 비교
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
