#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int max;        // 큐의 최대 용량
    int num;        // 현재 요소 개수
    int front;      // 프론트, 데이터를 꺼내는 방향
    int rear;       // 리어, 데이터를 넣는 방향
    int *que;       // 큐의 맨 앞 요소에 대한 위치
} Queue;

int Create(Queue *q, int max);          // 큐 메모리 생성
int Enque(Queue *q, int x);             // 큐에 데이터 인큐
int Deque(Queue *q, int *x);            // 큐에서 데이터 디큐
int Peek(const Queue *q, int *x);       // 맨 앞 데이터 확인
void Clear(Queue *q);                   // 모든 데이터 삭제
int Capacity(const Queue *q);           // 큐 최대 용량 확인
int Size(const Queue *q);               // 큐에 저장된 데이터 개수
int IsEmpty(const Queue *q);            // 큐가 비어 있는지 확인
int IsFull(const Queue *q);             // 큐가 가득 찼는지 확인
int Search(const Queue *q, int x);      // 큐에서 데이터 검색
void Print(const Queue *q);             // 큐 데이터 출력
void Terminate(Queue *q);               // 큐 메모리 소멸

int main() {
    
    Queue que;
    int n;
    
    printf("생성할 메모리 사이즈 : ");
    scanf("%d", &n);
    
    if(Create(&que, n) == -1) {
        printf("큐 메모리 생성 실패\n");
    }
    
    while(1) {
        int menu, x;
        
        printf("현재 데이터 수 : %d / %d\n", Size(&que), Capacity(&que));
        printf("(1)인큐 (2)디큐 (3)피크 (4)출력 (0)종료 : ");
        scanf("%d", &menu);
        
        if(menu == 0) {
            break;
        }
        
        switch(menu) {
            // 인큐
            case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            if(Enque(&que, x) == 1) {
                printf("인큐에 실패하였습니다.\n");
            }
            break;
            
            // 디큐
            case 2:
            if(Deque(&que, &x) == -1) {
                printf("디큐에 실패하였습니다.\n");
            }
            else {
                printf("디큐한 데이터는 %d 입니다.\n", x);
            }
            break;
            
            // 피크
            case 3:
            if(Peek(&que, &x) == -1) {
                printf("피크에 실패하였습니다.\n");
            }
            else {
                printf("피크한 데이터는 %d 입니다.\n", x);
            }
            break;
            
            // 출력
            case 4:
            Print(&que);
            break;
            default:
            printf("다시 입력해주세요.\n");
            break;
        }
    }
    
    Terminate(&que);

    return 0;
}

// 큐 메모리 생성
int Create(Queue *q, int max)
{
    if((q->que = malloc(sizeof(Queue) * max)) == NULL) {
        q->max = 0;
        
        return -1;
    }
    
    // if((q->que = calloc(max, sizeof(int))) == NULL) {
    //     q->max = 0;
    //     return -1;
    // }
    q->num = 0;
    q->front = 0;
    q->rear = 0;
    q->max = max;
    
    return 0;
}

// 큐에 데이터 인큐
int Enque(Queue *q, int x)
{
    // 큐가 가득 찼을 경우
    if(q->num >= q->max) {
        return -1;
    }
    else {
        q->num++;   // 현재 요소 개수 증가
        q->que[q->rear++] = x;      // 요소 개수가 증가하여 리어 값도 같이 증가
        
        // 리어 값이 최대 값이 되었을 때 리어 값을 0으로 초기화
        if(q->rear == q->max) {
            q->rear = 0;
        }
        
        return 0;
    }
}

// 큐에서 데이터 디큐
int Deque(Queue *q, int *x)
{
    // 큐가 비어 있을 경우
    if(q->num <= 0) {
        return -1;
    }
    else {
        q->num--;       // 현재 요소 개수 감소
        *x = q->que[q->front++];    // 요소 개수가 감소하여 프론트 값 증가
        
        // 프론트 값이 최대 값이 되었을 때 프론트 값을 0으로 초기화
        if(q->front == q->max) {
            q->front = 0;
        }
        
        return 0;
    }
}

// 현재 꺼낼 데이터 확인
int Peek(const Queue *q, int *x) 
{
    // 큐가 비어 있을 경우
    if(q->num <= 0) {
        return -1;
    }
    
    *x = q->que[q->front]; // 현재 꺼낼 데이터 값
    
    return 0;
}

// 모든 데이터 삭제
void Clear(Queue *q)
{
    // 현재 요소 개수와 프론트 리어 모두 0으로 초기화
    q->num = q->front = q->rear = 0;
}

// 큐 최대 사이즈
int Capacity(const Queue *q)
{
    return q->max;
}

// 큐에 쌓여 있는 데이터 개수
int Size(const Queue *q)
{
    return q->num;
}

// 큐가 비어 있는지 확인
int IsEmpty(const Queue *q)
{
    return q->num <= 0;   
}

// 큐가 가득 찼는지 확인
int IsFull(const Queue *q)
{
    return q->num >= q->max;
}

// 큐에서 데이터 검색
int Search(const Queue *q, int x)
{
    int i, idx;
    
    for(i = 0; i < q->num; i++) {
        idx = (i + q->front) % q->max;
        //if(q->que[idx = (i + q->front) % q->max] == x) {
        if(q->que[idx] == x) {
            return idx; // 검색 성공
        }
    }
    
    return -1;  // 검색 실패
}

// 큐에 있는 모든 데이터 출력
void Print(const Queue *q)
{
    int i;
    
    for(i = 0; i < q->num; i++) {
        printf("출력 데이터 [%d] %d\n", i, q->que[(i + q->front) % q->max]);
    }
}

// 큐 메모리 소멸
void Terminate(Queue *q)
{
    if(q->que != NULL) {
        free(q->que);
    }
    
    q->max = q->num = q->front = q->rear = 0;
}
