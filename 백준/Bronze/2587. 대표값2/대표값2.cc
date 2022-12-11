#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num, average = 0;
    
    vector<int> v;
    
    for(int i = 0; i < 5; i++) {
        cin >> num;
        
        v.push_back(num);
        average += num;
    }
    
    sort(v.begin(), v.end());
    
    cout << average / 5 << endl;
    cout << v[2] << endl;
    
    return 0;
}
