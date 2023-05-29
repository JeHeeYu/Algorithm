#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int N, number;
    
    vector<int> result;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> number;
        result.push_back(number);
    }
    
    sort(result.begin(), result.end());
    
    for(int i = 0; i < N; i++) {
        cout << result[i] << '\n';
    }

    return 0;
}
