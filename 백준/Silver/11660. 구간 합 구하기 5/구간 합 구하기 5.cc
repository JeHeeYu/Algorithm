#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 표의 크기
        M : 합을 구해야 하는 횟수
        array : 입력 받은 값을 저장할 배열
        sumArray : 합 배열
        x1 : 처음 찾을 x 좌표값
        y1 : 처음 찾을 y 좌표값
        x2 : 마무리 x 좌표값
        y2 : 마무리 y 좌표값
        result : 값을 저장할 변수
    */
    int N, M, x1, x2, y1, y2, result;
    
    cin >> N >> M;
    
    vector<vector<int>> array(N + 1, vector<int>(N + 1, 0));
    vector<vector<int>> sumArray(N + 1, vector<int>(N + 1, 0));
    
    // 구간 합을 구할 반복문
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            // 입력 받은 값을 일반 배열에 저장
            cin >> array[i][j];
            
            // 구간 합 구하기
            sumArray[i][j] = sumArray[i][j - 1] + sumArray[i - 1][j] - sumArray[i - 1][j - 1] + array[i][j];
        }
    }
    
    for(int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        
        // 구간 합 배열로 구한 정답
        int result = sumArray[x2][y2] - sumArray[x1 - 1][y2] - sumArray[x2][y1 - 1] + sumArray[x1 - 1][y1 - 1];
        
        cout << result << '\n';
    }

    return 0;
}
