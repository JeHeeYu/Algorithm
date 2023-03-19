#include <iostream>

using namespace std;

int checkArray[4];
int array[4];
int checkSecret = 0;

void Add(char c);
void Remove(char c);

int main()
{
    /*
        S: DNA 문자열의 길이
        P : 비밀번호로 사용할 부분 문자열의 길이
        result : 결과 값
        str : 입력받을 문자열
        checkArray : 'A', 'C', 'G', 'T'의 최소 개수
        array : 현재 상태를 저장할 배열
        checkSecret : 몇 개의 문자에 대한 개수를 충족했는지 판단
    */
    int S, P, result = 0;;
    
    cin >> S >> P;
    
    string str;
    
    cin >> str;
    
    // 'A', 'C', 'G', 'T'의 최소 개수 입력
    for(int i = 0; i < 4; i++) {
        cin >> checkArray[i];
        
        if(checkArray[i] == 0) {
            checkSecret++;
        }
    }
    
    // 초기 P 문자열 처리
    for(int i = 0; i < P; i++) {
        Add(str[i]);
    }
    
    if(checkSecret == 4) {
        result++;
    }
    
    // 슬라이딩 윈도우 처리
    for(int i = P; i < S; i++) {
        int temp = i - P;
        
        Add(str[i]);
        Remove(str[temp]);
        
        if(checkSecret == 4) {
            result++;
        }
    }
    
    cout << result << '\n';

    return 0;
}

void Add(char c)
{
    switch(c) {
        case 'A':
            array[0]++;
            if(array[0] == checkArray[0]) {
                checkSecret++;
            }
            break;
        case 'C':
            array[1]++;
            if(array[1] == checkArray[1]) {
                checkSecret++;
            }
            break;
        case 'G':
            array[2]++;
            if(array[2] == checkArray[2]) {
                checkSecret++;
            }
            break;
        case 'T':
            array[3]++;
            if(array[3] == checkArray[3]) {
                checkSecret++;
            }
            break;
        default:
            break;
    }
}

void Remove(char c)
{
    switch(c) {
        case 'A':
            if(array[0] == checkArray[0]) {
                checkSecret--;
            }
            array[0]--;
            break;
        case 'C':
            if(array[1] == checkArray[1]) {
                checkSecret--;
            }
            array[1]--;
            break;
        case 'G':
            if(array[2] == checkArray[2]) {
                checkSecret--;
            }
            array[2]--;
            break;
        case 'T':
            if(array[3] == checkArray[3]) {
                checkSecret--;
            }
            array[3]--;
            break;
        default:
            break;
    }
}