void QuickSort(int *a, int left, int right);
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
    
    QuickSort(x, 0, n - 1);
    
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

void QuickSort(int *a, int left, int right)
{
    // 배열의 왼쪽 커서 (이하 그룹)
    int pl = left;
    
    // 배열의 오른쪽 커서 (이상 그룹)
    int pr = right;
    
    // 배열의 중앙 값을 피벗으로 설정
    int pivot = a[(pl + pr) / 2];
    
    int i;
    
    // 분할 과정 출력
    printf("a[%d] ~ a[%d] : {", left, right);
    for(i = left; i < right; i++) {
        printf("%d, ", a[i]);
    }
    printf("%d}\n", a[right]);
    
    
    do {
        // 왼쪽 커서가 중앙을 넘어갔을 때(이하 -> 이상 교차)
        while(a[pl] < pivot) {
            pl++;
        }
        // 오른쪽 커서가 중앙을 넘어갔을 때 (이상 >- 이하 교차)
        while(a[pr] > pivot) {
            pr--;
        }
        
        // 이하 그룹과 이상 그룹이 교차했을 경우 값 교환
        if(pl <= pr) {
            Swap(&a[pl], &a[pr]);
            pl++;
            pr--;
        }
        
        // 피벗의 이상 이하 그룹 정렬
    } while(pl <= pr);
    
    if(left < pr) {
        QuickSort(a, left, pr);
    }
    if(pl < right) {
        QuickSort(a, pl, right);
    }
}
