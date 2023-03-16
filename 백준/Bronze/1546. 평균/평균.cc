#include <iostream>

using namespace std;

int main()
{
    int N, M = 0, sum = 0;
    
    int array[1000];
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> array[i];
    }
    
    for(int i = 0; i < N; i++) {
        if(array[i] > M) {
            M = array[i];
        }
        
        sum += array[i];
    }
    
    double result = sum * 100.0 / M / N;
    
    cout << result << '\n';

    return 0;
}
