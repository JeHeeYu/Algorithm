#include <iostream>

using namespace std;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    
    int X, N, price, number;
    
    cin >> X >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> price >> number;
        
        X -= (price * number);
    }
    
    if(X == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    return 0;
}