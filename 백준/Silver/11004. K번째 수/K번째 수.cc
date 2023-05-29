#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int> &A, int S, int E, int K);
int partition(vector<int> &A, int S, int E);
void swap(vector<int> &A, int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, K;
    
    cin >> N >> K;
    
    vector<int> A(N, 0);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    quickSort(A, 0, N - 1, K - 1);
    cout << A[K-1];
}

void quickSort(vector<int> &A, int S, int E, int K)
{
    int pivot = partition(A, S, E);
    
    // 더 이상 구할 필요 없음
    if(pivot == K) {
        return;
    }
    // 왼쪽 그룹만 정렬 수행
    else if(K < pivot) {
        quickSort(A, S, pivot - 1, K);
    }
    // 오른쪽 그룹만 정렬 수행
    else {
        quickSort(A, pivot + 1, E, K);
        
    }
}

int partition(vector<int> &A, int S, int E)
{
    if(S + 1 == E) {
        if(A[S] > A[E]) {
            swap(A, S, E);
        }
        
        return E;
    }
    
    int M = (S + E) / 2;
    swap(A, S, M);
    
    int pivot = A[S];
    int i = S + 1, j = E;
    
    while(i <= j) {
        // 피벗보다 작은 수가 나올 때까지 j--
        while(pivot < A[j] && j > 0) {
            j--;
        }
        // 피벗보다 큰 수가 나올 때까지 i++
        while(pivot > A[i] && i < A.size() - 1) {
            i++;
        }
        if(i <= j) {
            // 찾은 i와 j 교환
            swap(A, i++, j--);
        }
    }
    
    // i == j 피벗의 값을 양쯕으로 분리한 가운데에 오도록 설정
    
    A[S] = A[j];
    A[j] = pivot;
    
    return j;
}

void swap(vector<int> &A, int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}