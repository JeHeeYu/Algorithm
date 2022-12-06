#include <stdio.h>
#include <stdlib.h>

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
        Pop(&q);
        Push(&q, Front(&q));
        Pop(&q);
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
    q->num++;
    
    q->que[q->rear] = data;
    q->rear++;
}

void Pop(Queue *q)
{
    q->num--;
    q->front++;
}

int Size(Queue *q)
{
    return q->num;
}

int Front(Queue *q)
{
    return q->que[q->front];
}
