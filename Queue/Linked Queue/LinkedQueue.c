#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
typedef struct _Node
{
    char* data;             // 노드에 담을 데이터
    struct _Node* nextNode;     // 다음 노드에 대한 포인터
} Node;

typedef struct _LinkedQueue
{
    Node* front;     // 전단을 가리킴
    Node* rear;      // 후단을 가리킴
    int count;       // 노드 개수
} LinkedQueue;

void CreateQueue(LinkedQueue** queue);
void DestroyQueue(LinkedQueue* queue);

Node* CreateNode(char* newData);
void DestroyNode(Node* node);

void Enqueue(LinkedQueue* queue, Node* newNode);
Node* Dequeue(LinkedQueue* queue);

int IsEmpty(LinkedQueue* queue);

int main() 
{
    Node* temp;
    LinkedQueue* queue;
    
    CreateQueue(&queue);
    
    Enqueue(queue, CreateNode("abc"));
    Enqueue(queue, CreateNode("def"));
    Enqueue(queue, CreateNode("ghi"));
    Enqueue(queue, CreateNode("jkl"));
    
    printf("Queue Size : %d\n", queue->count);
    
    while(IsEmpty(queue) == 0) {
        temp = Dequeue(queue);
        
        printf("Deque : %s\n", temp->data);
        
        DestroyNode(temp);
    }
    
    DestroyQueue(queue);

    return 0;
}

void CreateQueue(LinkedQueue** queue)
{
    // 큐 생성
    (*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    
    // 필드 초기화
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->count = 0;
}

void DestroyQueue(LinkedQueue* queue)
{
    // 노드가 있을 경우 삭제
    while(!IsEmpty(queue)) {
        Node* temp = Dequeue(queue);
        DestroyNode(temp);
    }
    
    // 큐 삭제
    free(queue);
}

Node* CreateNode(char* newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(newData) + 1);
    
    // 데이터 저장
    strcpy(newNode->data, newData);
    
    // 다음 노드에 대한 포인터는 NULL로 초기화
    newNode->nextNode = NULL;
    
    // 노드 주소 반환
    return newNode;
}

void DestroyNode(Node* node)
{
    free(node->data);
    free(node);
}

void Enqueue(LinkedQueue* queue, Node* newNode)
{
    // 전단이 없는 경우 처음 노드 생성임
    if(queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        queue->count++;
    }
    // 다음 노드에 삽입할 노드 할당
    else {
        queue->rear->nextNode = newNode;
        queue->rear = newNode;
        queue->count++;
    }
}

Node* Dequeue(LinkedQueue* queue)
{
    // 반환할 최상위 노드
    Node* front = queue->front;
    
    if(queue->front->nextNode == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    // 전단 뒤에 있는 노드를 새로운 노드로 만듦
    else {
        queue->front = queue->front->nextNode;
    }
    
    queue->count--;
    
    return front;
}

int IsEmpty(LinkedQueue* queue)
{
    return queue->front == NULL;
}
