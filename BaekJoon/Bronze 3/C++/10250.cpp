#include <iostream>

using namespace std;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    
    int T, H, W, N, hTemp, wTemp;
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        cin >> H >> W >> N;    
        
        // 층수, 10 % 6 나누면 4, 즉 4층
        hTemp = N % H;
        
        // 10 / 6은 1로, 호수
        wTemp = N / H;
        
        if(hTemp > 0) {
            wTemp++;
        }
        else {
            hTemp = H;
        }
        
        cout << hTemp * 100  + wTemp << endl;
    }
    

    return 0;
}
