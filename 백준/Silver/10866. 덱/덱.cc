#include <iostream>
#include <deque>

using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    deque<int> d;
    
    int N, number;
    
    string str;
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> str;
        
        if(str == "push_front") {
            cin >> number;
            
            d.push_front(number);
        }
        
        else if(str == "push_back") {
            cin >> number;
            
            d.push_back(number);
        }
        
        else if(str == "pop_front") {
            if(d.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        
        else if(str == "pop_back") {
            if(d.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        
        else if(str == "size") {
            cout << d.size() << '\n';
        }
        
        else if(str == "empty") {
            if(d.size() == 0) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        
        else if(str == "front") {
            if(d.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << d.front() << '\n';
            }
        }
        
        else {
            if(d.size() == 0) {
                cout << "-1\n";
            }
            else {
                cout << d.back() << '\n';
            }
        }
    }

    return 0;
}
