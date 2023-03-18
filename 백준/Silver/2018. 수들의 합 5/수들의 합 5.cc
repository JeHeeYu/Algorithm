#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        N : 입력 받을 값
        start : 시작 포인터 값
        end : 끝 포인터 값
        sum : N과 비교할 start와 end를 더한 값
        result : N과 같은 횟수
    */
    
    int N, start = 1, end = 1, sum = 1, result = 1;
    
    cin >> N;
    
    while(end != N) {
        // 합과 N이 같을 경우
        if(sum == N) {
            // 찾은 횟수 1씩 증가
            result++;
            end++;
            sum += end;
        }
        // 합이 N보다 클 때
        else if(sum > N) {
            sum -= start;
            start++;
        }
        // 합이 답보다 작을 때
        else {
            end++;
            sum += end;
        }
    }
    
    cout << result << '\n';

    return 0;
}
