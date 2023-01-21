#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(pair<int, string> age, pair<int, string> name)
{
    return age.first < name.first;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int N;
    
    int age;
    string name;
    
    vector<pair<int, string>> v;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> age >> name;
        
        v.push_back(make_pair(age, name));
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << '\n';
    }

    return 0;
}
