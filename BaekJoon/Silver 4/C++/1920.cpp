#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int Search(int* arr, int size, int key);

int main()
{
    cin.tie(NULL);
	ios::sync_with_stdio(false);
    
    int N, M, number;
    int arr[100001];
    
    cin >> N;
    
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    // 이진 탐색을 위한 정렬
    sort(arr, arr + N);
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> number;
        
        cout << Search(arr, N, number) << "\n";
    }

    return 0;
}

// arr : 검색할 배열, size : 검색할 배열 사이즈, key : 찾을 값 
int Search(int* arr, int size, int key)
{
    // 맨 앞 인덱스
    int first = 0;
    
    // 맨 끝 인덱스
    int last = size - 1;
    
    // 중간 인덱스
    int middle;
    
    while(first <= last) {
        // 중간 값 설정
        middle = (first + last) / 2;
         
        // 중간 값이 찾고자 하는 값일 경우 1 리턴
        if(arr[middle] == key) {
            return 1;
        }
        // 찾고자 하는 값이 중간 값보다 클 경우 탐색 범위를 우측으로 축소
        else if(arr[middle] < key) {
            first = middle + 1;
        }
        // 찾고자 하는 값이 중간 값보다 작을 경우 탐색 범위를 좌측으로 축소
        else {
            last = middle - 1;
        }
    }
 
    // 값을 찾지 못했을 경우   
    return 0;
}
