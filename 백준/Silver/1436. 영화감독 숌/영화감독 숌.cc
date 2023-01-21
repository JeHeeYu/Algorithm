#include <iostream>

using namespace std;

int main()
{
    
    /*
    N : N번째 영화
    name : 영화 제목
    count : 현재 몇 번째 종말의 수 인지
    temp : 종말의 수 인지 판단할 변수
    */
    int N;
    int name = 0, number = 0, count = 0, temp = 0;
    
    cin >> N;
    
    while(N != count) {
        name++;
        temp = name;
        
        // 종말의 수 인지 계산
        while(temp != 0) {
            // 종말의 수 일 경우
            if(temp % 1000 == 666) {
                count++;
                break;
            }
            
            // 아닐 경우 한 자리씩 삭제
            else {
                temp /= 10;
            }
        }
    }
    
    cout << name;

    return 0;
}
