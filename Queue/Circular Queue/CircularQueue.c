#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
} Node;

typedef struct _CircleQueue
{
    int capacity; // 큐의 용량
    int front;    // 전단 위치
    int rear;     // 후단 위치
    
    Node* node;   // 요소 데이터
} CircularQueue;

void CreateQueue(CircularQueue** queue, int capacity);
void DestroyQueue(CircularQueue* queue);
void Enqueue(CircularQueue* queue, int data);
int Dequeue(CircularQueue* queue);
int IsEmpty(CircularQueue* queue);
int IsFull(CircularQueue* queue);
int GetSize(CircularQueue* queue);

int main() 
{
    int i;
    CircularQueue* queue;
    
    CreateQueue(&queue, 10);
    
    Enqueue(queue, 1);
    Enqueue(queue, 2);
    Enqueue(queue, 3);
    Enqueue(queue, 4);
    
    for(i = 0; i < 3; i++) {
        printf("Dequeue : %d ", Dequeue(queue));
        printf("Front : %d Rear : %d\n", queue->front, queue->rear);
    }
    
    i = 100;
    
    while(IsFull(queue) == 0) {
        Enqueue(queue, i++);
    }
    
    printf("Capacity : %d, Size : %d\n\n", queue->capacity, GetSize(queue));
    
    while(IsEmpty(queue) == 0) {
        printf("Dequeue : %d ", Dequeue(queue));
        printf("Front : %d Rear : %d\n", queue->front, queue->rear);
    }
    
    DestroyQueue(queue);

    return 0;
}

void CreateQueue(CircularQueue** queue, int capacity)
{
    (*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    
    // 크기 1만큼 +해서 메모리 생성
    (*queue)->node = (Node*)malloc(sizeof(Node) * (capacity + 1));
    
    (*queue)->capacity = capacity;
    (*queue)->front = 0;
    (*queue)->rear = 0;
}

void DestroyQueue(CircularQueue* queue)
{
    // 원형 큐가 가리키는 노드 소멸
    free(queue->node);
    
    // 원형 큐 소멸
    free(queue);
}

void Enqueue(CircularQueue* queue, int data)
{
    // 현재 위치를 가리킬 변수
    int position = 0;
    
    // 큐가 가득 찼을 때
    if(queue->rear == queue->capacity) {
        position = queue->rear;
        queue->rear = 0;
    }
    // 큐가 가득 차지 않았을 때
    else {
        // 현재 위치 1씩 증가
        position = queue->rear++;
        //queue->rear++;
    }
    
    queue->node[position].data = data;
}

int Dequeue(CircularQueue* queue)
{
    int position = queue->front;
    
    if(queue->front == queue->capacity) {
        queue->front = 0;
    }
    else {
        queue->front++;   
    }
    
    return queue->node[position].data;
}

int IsEmpty(CircularQueue* queue)
{
    return (queue->front == queue->rear);
}

int IsFull(CircularQueue* queue)
{
    // 같을 경우 포화 상태
    if(queue->front < queue->rear) {
        return (queue->rear - queue->front) == queue->capacity;
    }
    // 같을 경우 포화 상태
    else {
        return (queue->rear + 1) == queue->front;
    }
}

int GetSize(CircularQueue* queue)
{
    // 전단이 후단보다 뒤에 있을 경우 그냥 빼서 리턴
    if(queue->front <= queue->rear) {
        return queue->rear - queue->front;
    }
    // 전단이 후단보다 앞에 있을 경우
    else {
        queue->rear + (queue->capacity - queue->front) + 1;
    }
}
