#include <stdio.h>
#include <stdlib.h>

/* que : 큐 데이터를 담을 배열
   num : 현재 개수
   front : 큐 배열에서 앞 인덱스 값
   rear : 큐 배열에서 뒤 인덱스 값
*/

typedef struct _Queue
{
    int *que;
    int num;
    int front;
    int rear;
} Queue;

void CreateQueue(Queue *q, int size);
void Push(Queue* q, int data);
void Pop(Queue *q);
int Size(Queue *q);
int Front(Queue *q);

int main()
{
    int N, i;
    Queue q;
    
    scanf("%d", &N);
    
    CreateQueue(&q, N);
    
    for(i = 1; i <= N; i++) {
        Push(&q, i);
    }
    
    while(Size(&q) > 1) {
        Pop(&q);  // 처음 카드 버림
        Push(&q, Front(&q));  // 맨 앞의 카드 값을 뒤로 보냄
        Pop(&q); // 다시 카드 버림
    }
    
    printf("%d\n", Front(&q));
    
    return 0;
}

void CreateQueue(Queue *q, int size)
{
    q->que = malloc(sizeof(Queue) * size);
    
    q->num = 0;
    q->front = 0;
    q->rear = 0;
}

void Push(Queue* q, int data)
{
    // Push하여 총 개수 증가
    q->num++;
    
    // 배열에 데이터 Push
    q->que[q->rear] = data;
    
    // 큐의 Rear 값 증가 배열이 1칸씩 뒤로 밀림
    q->rear++;
}

void Pop(Queue *q)
{
    // 총 개수 감소
    q->num--;
    
    // front값 증가 배열이 1칸씩 뒤로 밀림
    q->front++;
}

int Size(Queue *q)
{
    // 현재 개수
    return q->num;
}

int Front(Queue *q)
{
    // 현재 가장 앞의 값
    return q->que[q->front];
}
