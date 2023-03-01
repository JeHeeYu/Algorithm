#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_WEIGHT 32767

// 데이터를 담을 노드
typedef struct _Node
{
    int priority;   // 출력해야할 우선순위
    void* data;     // 노드 값
} Node;

// 우선순위 큐에 대한 구조체
typedef struct _PriorityQueue
{
    Node* node;     // 데이터를 담을 노드
    int capacity;   // node의 크기
    int usedSize;   // node 안에 들어있는 큐 요소의 수
} PriorityQueue;
    
// 정점에 대한 구조체
typedef struct _Vertex
{
    int data;       // 정점에 저장할 데이터
    int visited;    // 정점 방문 여부
    int index;      // 정점의 인덱스 첫 번째 0.. 두 번째 1.. 식으로 증가
    
    struct _Vertex* next;       // 다음 정점을 가리키는 포인터
    struct _Edge* adjacencyList;    // 인접 정점의 목록에 대한 포인터
} Vertex;

typedef struct _Edge
{
    int weight;         // 필드 간선의 가중치
    struct _Edge* next; // 다음 간선을 가리키는 포인터
    Vertex* from;       // 간선의 시작 정점
    Vertex* target;     // 간선의 끝 정점

} Edge;

// 그래프의 구조체
typedef struct _Graph
{
    Vertex* vertices;   // 정점 목록에 대한 포인터
    int vertexCount;    // 정점 수
} Graph;


// 큐 생성
PriorityQueue* CreateQueue(int size);

// 큐 제거
void DestroyQueue(PriorityQueue* pq);

// 큐에 데이터 삽입
void Enqueue(PriorityQueue* pq, Node newNode);

// 큐에서 데이터 제거
void Dequeue(PriorityQueue* pq, Node* root);

// 부모 노드 값
int GetParent(int index);

// 왼쪽 자식 노드 값
int GetLeftChild(int index);

// 노드 값 교환
void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex);

// 노드 비었는지 확인
int IsEmpty(PriorityQueue* pq);

// 그래프 생성
Graph* createGraph();

// 그래프 제거
void DestroyGraph(Graph* g);

// 정점 추가
Vertex* CreateVertex(int data);

// 정점 제거
void DestroyVertex(Vertex* v);

// 정점 추가
void AddVertex(Graph* g, Vertex* v);

// 간선 추가
Edge* CreateEdge(Vertex* from, Vertex* target, int weight);

// 간선 제거
void DestroyEdge(Edge* e);

// 간선 추가
void AddEdge(Vertex* v, Edge* e);

// 노드 생성
Node* CreateNode(Vertex* newData);

// 노드 제거
void DestroyNode(Node* node);

// 노드 추가
void AppendNode(Node** head, Node* newNode);

// 노드 삽입
void InsertNode(Node* current, Node* newNode);

// 헤드 삽입
void InsertHead(Node** head, Node* newHead);

// 노드 삭제
void RemoveNode(Node** head, Node* removeNode);

// 프림 알고리즘
void Prim(Graph* g, Vertex* startVertex, Graph* tree);

int main() 
{

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

void Prim(Graph* g, Vertex* startVertex, Graph* tree)
{
    int i = 0;
    
    Node startNode = { 0, startVertex };
    PriorityQueue* queue = CreateQueue(10);
    
    Vertex* currentVertex = NULL;
    Edge* currentEdge = NULL;
    
    int* weights = (int*)malloc(sizeof(int) * g->vertexCount);
    Vertex** treeVertices = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
    Vertex** fringes = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
    Vertex** precedences = (Vertex**)malloc(sizeof(Vertex*) * g->vertexCount);
    
    currentVertex = g->vertices;
    
    // 빈 정점이 아닐 경우
    while(currentVertex != NULL) {
        Vertex* newVertex = CreateVertex(currentVertex->data);
        AddVertex(tree, newVertex);
        
        fringes[i] = NULL;
        precedences[i] = NULL;
        treeVertices[i] = newVertex;
        weights[i] = MAX_WEIGHT;
        currentVertex = currentVertex->next;
        i++;
    }
    
    Enqueue(queue, startNode);
    
    weights[startVertex->index] = 0;
    
    while(!IsEmpty(queue)) {
        
    }
}
