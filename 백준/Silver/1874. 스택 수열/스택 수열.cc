#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        n : 수열 개수
        v : 수열을 저장할 배열
        result : + 또는 -를 저장할 결과 배열
        num : 오름차순 수
        s : 데이터를 저장할 스택
        resultFlag : NO 여부를 정할 Flag 변수
    */
    
    int n;
    int num = 1;
    
    cin >> n;
    
    vector<int> v(n, 0);
    vector<char> result;
    stack<int> s;
    bool resultFlag = true;
    
    // 정수 하나씩 입력 받기
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    for(int i = 0; i < v.size(); i++) {
        // 현재 수열 수
        int temp = v[i];
        
        // 현재 수열 값 >= 오름차순 자연수 간 값이 같아질 때까지 push 수행
        if(temp >= num) {
            while(temp >= num) {
                s.push(num++);
                result.push_back('+');
            }
            
            s.pop();
            result.push_back('-');
        }
        // 현재 수열 값 < 오름차순 자연수면 pop을 수행하여 수열 원소 꺼냄
        else {
            int n = s.top();
            s.pop();
            
            // 스택의 가장 위의 수가 만들어야 하는 수열의 수보다 크면 수열 출력 불가능
            if(n > temp) {
                cout << "NO";
                resultFlag = false;
                break;
            }
            else {
                result.push_back('-');
            }
        }
    }
    
    if(resultFlag) {
        for(int i = 0; i < result.size(); i++) {
            cout << result[i] << '\n';
        }
    }

    return 0;
}
