#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int *a, int n);
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
    
    SelectionSort(x, n);
    
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

void SelectionSort(int *a, int n)
{
    int i, j;
    
    for(i = 1; i < n; i++) {
        int temp = a[i];
        // 정렬되지 않은 데이터가 없을 때까지 반복
        for(j = i; j > 0 && a[j - 1] > temp; j--) {
            a[j] = a[j - 1];
        }
        // 요소 위치 교환
        a[j] = temp;
    }
}
