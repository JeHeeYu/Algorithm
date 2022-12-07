#include <stdio.h>

void Swap(int *a, int *b);
void Sort(int *arr, int left, int right);

int main()
{
    int N, k, num;
    int arr[1001] = { 0 };
    
    scanf("%d %d", &N, &k);
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }
    
    Sort(arr, 0, N - 1);
    
    printf("%d", arr[N - k]);

    return 0;
}

void Swap(int *a, int *b)
{
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void Sort(int *arr, int left, int right)
{
    int l = left;
    int r = right;
    
    int pivot = arr[(l + r) / 2];
    
    int i;
    
    while(l <= r) {
        while(arr[l] < pivot) {
            l++;
        }
        while(arr[r] > pivot) {
            r--;
        }
        
        if(l <= r) {
            Swap(&arr[l], &arr[r]);
            l++;
            r--;
        }
    }
    
    if(left < r) {
        Sort(arr, left, r);
    }
    if(l < right) {
        Sort(arr, l, right);
    }
}
