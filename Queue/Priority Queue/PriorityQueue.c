// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct _Node
{
    int priority;   // 출력해야할 우선순위
    void* data;     // 노드 값
} Node;

typedef struct _PriorityQueue
{
    Node* node;     // 데이터를 담을 노드
    int capacity;   // node의 크기
    int usedSize;   // node 안에 들어있는 큐 요소의 수
} PriorityQueue;

PriorityQueue* CreateQueue(int size);
void DestroyQueue(PriorityQueue* pq);
void Enqueue(PriorityQueue* pq, Node newNode);
void Dequeue(PriorityQueue* pq, Node* root);
int GetParent(int index);
int GetLeftChild(int index);
void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex);
int IsEmpty(PriorityQueue* pq);
void PrintNode(Node* node);

int main() 
{
    PriorityQueue* pq = CreateQueue(3);
    Node popped;
    
    Node nodes[7] = {
        {34, (void*)"코딩"},
        {12, (void*)"밥먹기"},
        {87, (void*)"커피타기"},
        {45, (void*)"문서작성"},
        {35, (void*)"디버깅"},
        {66, (void*)"이닦기"},
    };
    
    Enqueue(pq, nodes[0]);
    Enqueue(pq, nodes[1]);
    Enqueue(pq, nodes[2]);
    Enqueue(pq, nodes[3]);
    Enqueue(pq, nodes[4]);
    Enqueue(pq, nodes[5]);
    
    printf("큐에 남아 있는 작업의 수 : %d\n", pq->usedSize);

    while(!IsEmpty(pq)) {
        Dequeue(pq, &popped);
        PrintNode(&popped);
    }

    return 0;
}

PriorityQueue* CreateQueue(int size)
{
    PriorityQueue* newQueue = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    
    newQueue->capacity = size;
    newQueue->usedSize = 0;
    newQueue->node = (Node*)malloc(sizeof(Node) * newQueue->capacity);
    
    return newQueue;
}

void DestroyQueue(PriorityQueue* pq)
{
    free(pq->node);
    free(pq);
}

void Enqueue(PriorityQueue* pq, Node newNode)
{
    int currentPosition = pq->usedSize;
    int parentPosition = GetParent(currentPosition);
    
    if(pq->usedSize == pq->capacity) {
        if(pq->capacity == 0) {
            pq->capacity = 1;
        }
        
        pq->capacity *= 2;
        
        pq->node = (Node*)realloc(pq->node, sizeof(Node) * pq->capacity);
    }
    
    pq->node[currentPosition] = newNode;
    
    // 후속  처리
    while(currentPosition > 0 && pq->node[currentPosition].priority < pq->node[parentPosition].priority) {
        SwapNodes(pq, currentPosition, parentPosition);
        
        currentPosition = parentPosition;
        parentPosition = GetParent(currentPosition);
    }
    
    pq->usedSize++;
}

void Dequeue(PriorityQueue* pq, Node* root)
{
    int parentPosition = 0;
    int leftPosition = 0;
    int rightPosition = 0;
    
    memcpy(root, &pq->node[0], sizeof(Node));
    memset(&pq->node[0], 0, sizeof(Node));
    
    pq->usedSize--;
    SwapNodes(pq, 0, pq->usedSize);
    
    leftPosition = GetLeftChild(0);
    rightPosition = leftPosition + 1;
    
    while(1) {
        int selectChild = 0;
        
        if(leftPosition >= pq->usedSize) {
            break;
        }
        
        if(rightPosition >= pq->usedSize) {
            selectChild = leftPosition;
        }
        
        else {
            if(pq->node[leftPosition].priority > pq->node[rightPosition].priority) {
                selectChild = rightPosition;
            }
            else {
                selectChild = leftPosition;
            }
        }
        
        if(pq->node[selectChild].priority < pq->node[parentPosition].priority) {
            SwapNodes(pq, parentPosition, selectChild);
            parentPosition = selectChild;
        }
        
        else {
            break;
        }
        
        leftPosition = GetLeftChild(parentPosition);
        rightPosition = leftPosition + 1;
    }
    
    if(pq->usedSize < (pq->capacity / 2)) {
        pq->capacity /= 2;
        pq->node = (Node*)realloc(pq->node, sizeof(Node) * pq->capacity);
    }
}

int GetParent(int index)
{
    return (int) ((index - 1) / 2);
}

int GetLeftChild    (int index)
{
    return (2 * index) + 1;
}

void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex)
{
    int copySize = sizeof(Node);
    
    Node* temp = (Node*)malloc(copySize);
    
    memcpy(temp, &pq->node[aIndex], copySize);
    memcpy(&pq->node[aIndex], &pq->node[bIndex], copySize);
    memcpy(&pq->node[bIndex], temp, copySize);
    
    free(temp);
}

int IsEmpty(PriorityQueue* pq)
{
    return (pq->usedSize == 0);
}

void PrintNode(Node* node)
{
    printf("작업명 : %s (우선순위 : %d)\n", node->data, node->priority);
}
