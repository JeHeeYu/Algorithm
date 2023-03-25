#include <iostream>
#include <vector>

using namespace std;

void MergeSort(int a, int b);

static vector<int> v;
static vector<int> temp;
static long result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    
    cin >> N;
    
    v = vector<int>(N + 1, 0);
    temp = vector<int>(N + 1, 0);
    
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    
    result = 0;
    MergeSort(1, N);
    
    cout << result << '\n';
    

    return 0;
}

void MergeSort(int a, int b)
{
    if(b - a < 1) {
        return;
    }
    
    int m = a + (b - a) / 2;
    
    // 재귀 함수 구현
    MergeSort(a, m);
    MergeSort(m + 1, b);
    
    for(int i = a; i <= b; i++) {
        temp[i] = v[i];
    }
    
    int k = a;
    int start = a;
    int end = m + 1;
    
    // 두 그룹을 병합하는 반복문
    while(start <= m && end <= b) {
        if(temp[start] > temp[end]) {
            v[k] = temp[end];
            
            // 뒷 부분 데이터 값이 작아 선택되는 경우 결괏값 업데이트
            result = result + end - k;
            k++;
            end++;
        }
        else {
            v[k] = temp[start];
            k++;
            start++;
        }
    }
    
    while(start <= m) {
        v[k] = temp[start];
        k++;
        start++;
    }
    
    while(end <= b) {
        v[k] = temp[end];
        k++;
        end++;
    }
}