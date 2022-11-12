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
    
    for(i = 0; i < n; i++) {
        // min 값 정의
        int min = i;
        for(j = i + 1; j < n; j++) {
            // 전체 배열에서 min값 확인
            if(a[j] < a[min]) {
                min = j;
            }
            
            // 정렬되지 않은 앞쪽 인덱스와 가장 작은 값 교환
            Swap(&a[i], &a[min]);
        }
    }
}
