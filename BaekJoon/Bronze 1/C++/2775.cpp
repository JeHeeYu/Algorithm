#include <iostream>

using namespace std;

int main() 
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int T, n, k;
    
    // 층 호수
    int arr[15][15] = { 0 };
    
    cin >> T;
    
    for(int i = 0; i < T; i++) {
        // Test case 입력
        cin >> k >> n;
        
        // k층까지 반복
        for(int i = 0; i <= k; i++) {
            
            // n 호수까지 반복
            for(int j = 1; j <= n; j++) {
                
                // 0층일 경우 기본 1 ~ n 층이라 미리 할당
                if(i == 0) {
                    arr[0][j] = j;       
                }
                
                // 1호 일 경우 무조건 1
                else if(j == 1) {
                    arr[i][1] = 1;
                }
                
                // 층 및 호수 계산
                else {
                    arr[i][j] = arr[i][j - 1] + arr[i - 1][j];
                }
            }
        }
        
        cout << arr[k][n] << endl;
    }

    return 0;
}
