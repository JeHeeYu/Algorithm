#include <stdio.h>
#include <stdlib.h>

int BinarySearch(const int *a, int n, int key);

int main() {
    int i, n, key, index;
    int *x;
    
    printf("요소 개수 : ");
    scanf("%d", &n);
    
    x = malloc(sizeof(int) * n);
    
    printf("오름차순 입력\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    
    for(i = 1; i < n; i++) {
        do {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
            // 바로 앞의 값보다 작을 경우 다시 입력
        } while(x[i] < x[i - 1]);
    }
    
    printf("검색 값 : ");
    scanf("%d", &key);
    
    index = BinarySearch(x, n, key);
    
    if(index == -1) {
        printf("검색 실패!");
    }
    else {
        printf("%d 값은 x[%d]에 있음!\n", key, index);
    }
    
    free(x);

    return 0;
}

// a : 검색할 배열, n : 배열 사이즈, key : 찾을 값
int BinarySearch(const int *a, int n, int key)
{
    // 맨 앞 인덱스
    int pl = 0;
    
    // 맨 마지막 인덱스
    int pr = n - 1;
    
    // 중앙 인덱스
    int pc;
    
    do {
        // 중간 값
        pc = (pl + pr) / 2;
        
        // 검색 성공
        if(a[pc] == key) {
            return pc;
        }
        // 중앙 값이 key보다 작을 때
        else if(a[pc] < key){
            // pl의 값을 좁혀진 범위에서의 앞 인덱스로 업데이트
            pl = pc + 1;
        }
        // 중앙 값이 key보다 클 때
        else {
            // pr의 값을 좁혀진 범위에서의 끝 인덱스로 업데이트
            pr = pc - 1;
        }
    } while(pl <= pr);
    
    // 검색 실패
    return -1;
}
