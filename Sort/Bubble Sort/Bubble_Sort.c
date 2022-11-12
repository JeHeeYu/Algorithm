#include <stdio.h>
#include <stdlib.h>

void BubbleSort(int *a, int n);
void Swap(int* num1, int* num2);

int main() 
{
    int i, n;
    int *x;
    
    printf("요소 개수 : ");
    scanf("%d", &n);
    
    x = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    
    BubbleSort(x, n);
    
    printf("오름차순 정렬\n");
    
    for(i = 0; i < n; i++) {
        printf("x[%d] = %d\n", i, x[i]);
    }
    
    free(x);

    return 0;
}

void Swap(int* num1, int* num2) 
{  
    int temp;
    
    temp = *num2;
    *num2 = *num1;
    *num1 = temp;
}

void BubbleSort(int a[], int n)
{
    int i, j;
    
    // 첫 번째 요소부터 마지막 요소까지 반복
    for(i = 0; i < n - 1; i++) {
        // 마지막 요소부터 첫 번째 요소까지 반복
        for(j = n - 1; j > i; j--) {
            // 인접한 요소 2개 비교해서 왼쪽 요소 값이 더 크면 위치 변경
            if(a[j - 1] > a[j]) {
                Swap(&a[j - 1], &a[j]);
            }
        }
    }
}
