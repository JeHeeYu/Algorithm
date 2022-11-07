#include <stdio.h>
#include <stdlib.h>

typedef struct _Stack
{
    int capacity;
    int top;
    int *buf;
} Stack;


int Create(Stack* s, int capacity);
int Push(Stack* s, int x);
int Pop(Stack* s, int* x);
int Peek(const Stack* s, int* x);
void Clear(Stack* s);
int Capacity(const Stack* s);
int Size(const Stack* s);
int IsEmpty(const Stack* s);
int IsFull(const Stack* s);
int Search(const Stack* s, int x);
void Print(const Stack* s);
void Terminate(Stack* s);

int main() 
{
    Stack s;
    int n;
    
    printf("생성할 메모리 사이즈 : ");
    scanf("%d", &n);
    
    if(Create(&s, n) == -1) {
        printf("스택 생성 실패\n");
        return 1;
    }
    
    while(1) {
        int menu, x;
        printf("현재 데이터 수 : [%d] / [%d]\n", Size(&s), Capacity(&s));
        
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
        scanf("%d", &menu);
        
        if(menu == 0) {
            printf("종료합니다.\n");
            break;
        }
        
        switch(menu) {
            // 푸쉬
            case 1:
            printf("데이터 : ");
            scanf("%d", &x);
            if(Push(&s, x) == -1) {
                printf("푸쉬에 실패하였습니다.\n");
            }
            break;
            
            // 팝
            case 2:
            if(Pop(&s, &x) == 1) {
                printf("팝에 실패하였습니다.\n");
            }
            else {
                printf("팝 데이터는 %d입니다.\n", x);
            }
            break;
            
            // 피크
            case 3:
            if(Peek(&s, &x) == 1) {
                printf("피크에 실패하였습니다.\n");
            }
            else {
                printf("피크 데이터는 %d입니다.\n", x);
            }
            break;
            
            // 출력
            case 4:
            Print(&s);
            break;
            
            default:
            printf("다시 입력해주세요.\n");
            break;
        }
    }
    
    Terminate(&s);

    return 0;
}

int Create(Stack* s, int capacity)
{
    //s->buf = calloc(capacity, sizeof(int));
    s->buf = malloc(sizeof(Stack) * capacity);
    s->top = 0;
    s->capacity = capacity;
}

int Push(Stack* s, int x)
{
    // 스택이 가득 차 있는지 확인
    if(s->top >= s->capacity) {
        printf("스택이 가득 찼습니다.\n");
        return -1;
    }
    
    // 스택에 푸쉬하여 데이터 증가
    s->buf[s->top++] = x;
    
    return 0;
}

int Pop(Stack* s, int* x)
{
    // 스택이 비어 있는지 확인
    if(s->top <= 0) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    
    // 스택에서 팝하여 데이터 감소
    *x = s->buf[s->top--];
    
    return 0;
}

int Peek(const Stack* s, int* x) 
{
    // 스택이 비어 있는지 확인
    if(s->top <= 0) {
        printf("스택이 비어 있습니다.\n");
        return -1;
    }
    
    // 최상위 데이터 확인
    *x = s->buf[s->top - 1];
    
    return 0;
}

void Clear(Stack* s)
{
    // 현재 가리키고 있는 top을 0으로 초기화
    s->top = 0;
}

int Capacity(const Stack* s)
{
    // 스택 최대 사이즈 
    return s->capacity;
}

int Size(const Stack* s)
{
    // 스택에 쌓여 있는 데이터 수
    return s->top;
}

int IsEmpty(const Stack* s)
{
    // 현재 가리키는 값이 최대 0보다 낮은지 확인
    return s->top <= 0;
}

int IsFull(const Stack* s)
{
    // 현재 가리키는 값이 최대 사이즈보다 높은지 확인
    return s->top >= s->capacity;
}

void Print(const Stack* s)
{
    int i;
    for(i = 0; i < s->top; i++) {
        printf("출력 데이터 [%d] %d\n: ", i, s->buf[i]);
    }
}

void Terminate(Stack* s)
{
    // 메모리가 비어 있지 않을 경우 소멸
    if(s->buf != NULL) {
        free(s->buf);
    }
    s->capacity = 0;
    s->top = 0;
}
