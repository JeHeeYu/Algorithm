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
    
    sort(arr, arr + N);
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        cin >> number;
        
        cout << Search(arr, N, number) << "\n";
    }

    return 0;
}

int Search(int* arr, int size, int key)
{
    int first = 0;
    int last = size - 1;
    int middle;
    
    while(first <= last) {
         middle = (first + last) / 2;
         
         
        if(arr[middle] == key) {
            return 1;
        }
        else if(arr[middle] < key) {
            first = middle + 1;
        }
        else {
            last = middle - 1;
        }
    }
    
    return 0;
}