#include <stdio.h>
#include <stdlib.h>

// a : 배열, n : 요소 개수, key : 찾고자 하는 값
int LinearSearch(int *a, int n, int key)
{
    int i = 0;
    
    // 배열의 마지막 요소에 보초 추가
    a[n] = key;
    
    while(1) {
        if(a[i] == key) {
            break;
        }
        i++;
    }
    
    // 배열의 끝까지 검색했을 때 못찾으면 -1을 리턴
    return i == n ? -1 : i;
}

int main()
{
    int i, n, key, index;
    int *x;
    
    printf("요소 개수 : ");
    scanf("%d", &n);
    
    x = malloc(sizeof(int) * n);
    
    for(i = 0; i < n; i++) {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }
    
    printf("검색 값 : ");
    scanf("%d", &key);
    
    index = LinearSearch(x, n, key);
    
    if(index == -1) {
        printf("검색 실패!\n");
    }
    else {
        printf("%d = x[%d]에 있음\n", key, index);
    }
    
    free(x);
}
