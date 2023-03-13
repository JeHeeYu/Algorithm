#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /* N : 수의 개수
     M : 합을 구해야 할 회수
     start : 구간 합 시작 인덱스 = i
     end : 구간 합 끝 인덱스 = j
    */
    int N, M, start, end;
    
    // 구간 합 배열
    int array[100001] = { 0 };
    
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++) {
        int temp;
        
        cin >> temp;
        
        // 구간 합 구하기
        array[i] = array[i - 1] + temp;
    }
    
    for(int i = 0; i < M; i++) {
        cin >> start >> end;
        
        // j부터 i까지의 값 
        cout << array[end] - array[start - 1] << '\n';
    }

    return 0;
}
 
