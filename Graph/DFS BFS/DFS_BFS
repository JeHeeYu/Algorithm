#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 정점 방문 여부로 방문 : 0, 미방문 : 1
enum visitMode
{
    Visited,
    NotVisited
};

// 정점에 대한 구조체
typedef struct _Vertex
{
    int data;       // 저장할 데이터
    int visited;    // 방문 여부
    int index;      // 정점의 인덱스 첫 번째 0.. 두 번째 1.. 식으로 증가
    
    struct _Vertex* next;       // 다음 정점을 가리키는 포인터
    struct _Edge* adjacencyList;    // 인접 정점의 목록에 대한 포인터
} Vertex;

// 간선에 대한 구조체
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

// 데이터를 저장할 노드 구조체
typedef struct _Node
{
    Vertex* data;             // 노드에 담을 데이터
    struct _Node* nextNode;     // 다음 노드에 대한 포인터
} Node;

// 링크드 큐 구조체
typedef struct _LinkedQueue
{
    Node* front;     // 전단을 가리킴
    Node* rear;      // 후단을 가리킴
    int count;       // 노드 개수
} LinkedQueue;

void CreateQueue(LinkedQueue** queue);
void DestroyQueue(LinkedQueue* queue);

Node* CreateNode(Vertex* v);
void DestroyNode(Node* node);

void Enqueue(LinkedQueue* queue, Node* newNode);
Node* Dequeue(LinkedQueue* queue);

int IsEmpty(LinkedQueue* queue);

Graph* CreateGraph();
void DestroyGraph(Graph * g);

Vertex* CreateVertex(int data);
void DestroyVertex(Vertex* v);

Edge* CreateEdge(Vertex* from, Vertex* garget, int weight);
void DestroyEdge(Edge* e);

void AddVertex(Graph* g, Vertex* v);
void AddEdge(Vertex* v, Edge* e);

void DFS(Vertex* v);
void BFS(Vertex* v, LinkedQueue* queue);

int main() 
{
    int mode = 0;
    
    Graph* graph = CreateGraph();
    
    // 정점 생성
    Vertex* v1 = CreateVertex(1);
    Vertex* v2 = CreateVertex(2);
    Vertex* v3 = CreateVertex(3);
    Vertex* v4 = CreateVertex(4);
    Vertex* v5 = CreateVertex(5);
    Vertex* v6 = CreateVertex(6);
    Vertex* v7 = CreateVertex(7);
    
    // 간선 생성
    AddVertex(graph, v1);
    AddVertex(graph, v2);
    AddVertex(graph, v3);
    AddVertex(graph, v4);
    AddVertex(graph, v5);
    AddVertex(graph, v6);
    AddVertex(graph, v7);
    
    // 정점과 정점을 간선으로 잇기
    AddEdge(v1, CreateEdge(v1, v2, 0));
    AddEdge(v1, CreateEdge(v1, v3, 0));
    
    
    AddEdge(v2, CreateEdge(v2, v4, 0));
    AddEdge(v2, CreateEdge(v2, v5, 0));
    
    AddEdge(v3, CreateEdge(v3, v4, 0));
    AddEdge(v3, CreateEdge(v3, v6, 0));
    
    AddEdge(v4, CreateEdge(v4, v5, 0));
    AddEdge(v4, CreateEdge(v4, v7, 0));
    
    AddEdge(v5, CreateEdge(v5, v7, 0));
    
    AddEdge(v6, CreateEdge(v6, v7, 0));
    
    printf("\nEnter Mode : (0 : DFS, 1 : BFS) ");
    scanf("%d", &mode);
    
    // 깊이 우선 탐색
    if(mode == 0) {
        DFS(graph->vertices);
    }
    
    // 너비 우선 탐색
    else {
        LinkedQueue* queue = NULL;
        CreateQueue(&queue);
        
        // 너비 우선 탐색
        BFS(v1, queue);
        
        // 큐 제거
        DestroyQueue(queue);
    }
    
    // 그래프 제거
    DestroyGraph(graph);
    
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

Node* CreateNode(Vertex* v)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = v;
    
    // 다음 노드에 대한 포인터 NULL 초기화
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

Graph* CreateGraph()
{
    // 그래프 동적 메모리 할당
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = NULL;
    graph->vertexCount = 0;
    
    return graph;
}


void DestroyGraph(Graph* g)
{
    // 다음 정점이 데이터가 있을 경우 반복해서 해제
    while(g->vertices != NULL) {
        Vertex* vertices = g->vertices->next;
        DestroyVertex(g->vertices);
        g->vertices = vertices;
    }
    
    free(g);
}

Vertex* CreateVertex(int data)
{
    // 새로운 정점 생성
    Vertex* v = (Vertex*)malloc(sizeof(Vertex));
    
    v->data = data;
    v->next = NULL;
    v->adjacencyList = NULL;
    v->visited = NotVisited;
    v->index = -1;
    
    return v;
}

void DestroyVertex(Vertex* v)
{
    // 인접한 정점이 데이터가 있을 경우 반복해서 해제
    while(v->adjacencyList != NULL) {
        Edge* edge = v->adjacencyList->next;
        DestroyEdge(v->adjacencyList);
        v->adjacencyList = edge;
    }
    
    free(v);
}

Edge* CreateEdge(Vertex* from, Vertex* target, int weight)
{
    // 새로운 간선 생성
    Edge* e = (Edge*)malloc(sizeof(Edge));
    
    e->from = from;
    e->target = target;
    e->weight = weight;
    
    return e;
}


void DestroyEdge(Edge* e)
{
    free(e);
}

void AddVertex(Graph* g, Vertex* v)
{
    Vertex* vertexList = g->vertices;
    
    if(vertexList == NULL) {
        g->vertices = v;
    }
    
    else {
        while(vertexList->next != NULL) {
            vertexList = vertexList->next;
        }
        
        vertexList->next = v;
    }
    
    v->index = g->vertexCount++;
}

void AddEdge(Vertex* v, Edge* e)
{
    if(v->adjacencyList == NULL) {
        v->adjacencyList = e;
    }
    
    else {
        Edge* adjacencyList = v->adjacencyList;
        
        while(adjacencyList->next != NULL) {
            adjacencyList = adjacencyList->next;
        }
        
        adjacencyList->next = e;
    }
}


void DFS(Vertex* v)
{
    Edge* e = NULL;
    
    printf("%d ", v->data);
    
    // '방문' 표시
    v->visited = Visited;
    
    e = v->adjacencyList;
    
    // 현재 정점의 모든 인접 정점에 대해 재귀 호출
    while(e != NULL) {
        // 방문하지 않은 정점의 경우 탐색
        if(e->target != NULL && e->target->visited == NotVisited) {
            DFS(e->target);
        }
        
        e = e->next;
    }
}

void BFS(Vertex* v, LinkedQueue* queue)
{
    Edge* e = NULL;
    
    printf("%d ", v->data);
    v->visited = Visited;
    
    // 시작 정점을 큐에 삽입
    Enqueue(queue, CreateNode(v));
    
    // 큐가 비지 않았을 경우
    while(!IsEmpty(queue)) {
        // 큐에서 전단 제거
        Node* temp = Dequeue(queue);
        v = temp->data;
        e = v->adjacencyList;
        
        // 큐에서 꺼낸 정점의 인접 정점 조사
        while(e != NULL) {
            v = e->target;
            
            // 방문하지 않은 접점들 방문
            if(v != NULL && v->visited == NotVisited) {
                printf("%d ", v->data);
                v->visited = Visited;
                Enqueue(queue, CreateNode(v));
            }
            
            e = e->next;
        }
    }
}
