#include <iostream>

using namespace std;

int main()
{
    int n, number, result;
    
    while(1) {
        cin >> n;
        
        if(n == 0) {
            break;
        }
        
        number = n;
        result = 0;
        
        while(number) {
            result += number % 10;
            result *= 10;
            
            number /= 10;
        }
        
        result /= 10;
        
        if(n == result) {
            cout << "yes" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }

    return 0;
}
