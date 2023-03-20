#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    vector<int> v(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            int temp = 0;
            
            if(v[i] > v[j]) {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}
