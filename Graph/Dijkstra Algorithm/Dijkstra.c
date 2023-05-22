#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define MAX_WEIGHT 32767

// 정점 방문 여부로 방문 : 0, 미방문 : 1
enum visitMode
{
    Visited,
    NotVisited
};

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

PriorityQueue* CreateQueue(int size);
void DestroyQueue(PriorityQueue* pq);
void Enqueue(PriorityQueue* pq, Node newNode);
void Dequeue(PriorityQueue* pq, Node* root);
int GetParent(int index);
int GetLeftChild(int index);
void SwapNodes(PriorityQueue* pq, int aIndex, int bIndex);
int IsEmpty(PriorityQueue* pq);

// 그래프 생성
Graph* CreateGraph();

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

// 그래프 출력
void PrintGraph(Graph* g);

// 다익스트라 알고리즘
void Dijkstra(Graph* g, Vertex* startVertex, Graph* tree);


int main()
{
    // 그래프 생성
    Graph* graph = CreateGraph();
    Graph* tree = CreateGraph();
    
    // 정점 생성
    Vertex* A = CreateVertex('A');
    Vertex* B = CreateVertex('B');
    Vertex* C = CreateVertex('C');
    Vertex* D = CreateVertex('D');
    Vertex* E = CreateVertex('E');
    Vertex* F = CreateVertex('F');
    Vertex* G = CreateVertex('G');
    Vertex* H = CreateVertex('H');
    Vertex* I = CreateVertex('I');
    
    // 그래프에 정점 추가
    AddVertex(graph, A);
    AddVertex(graph, B);
    AddVertex(graph, C);
    AddVertex(graph, D);
    AddVertex(graph, E);
    AddVertex(graph, F);
    AddVertex(graph, G);
    AddVertex(graph, H);
    AddVertex(graph, I);
    
        //  정점과 정점을 간선으로 잇기 
    AddEdge( A, CreateEdge(A, B, 35) );
    AddEdge( A, CreateEdge(A, E, 247) );
    
    AddEdge( B, CreateEdge(B, A, 35  ) );
    AddEdge( B, CreateEdge(B, C, 126 ) );
    AddEdge( B, CreateEdge(B, F, 150 ) );

    AddEdge( C, CreateEdge(C, B, 126 ) );
    AddEdge( C, CreateEdge(C, D, 117 ) );
    AddEdge( C, CreateEdge(C, F, 162 ) );
    AddEdge( C, CreateEdge(C, G, 220 ) );
    
    AddEdge( D, CreateEdge(D, C, 117 ) );

    AddEdge( E, CreateEdge(E, A, 247 ) );
    AddEdge( E, CreateEdge(E, F, 82 ) );
    AddEdge( E, CreateEdge(E, H, 98 ) );

    AddEdge( F, CreateEdge(F, B, 150 ) );
    AddEdge( F, CreateEdge(F, C, 162 ) );
    AddEdge( F, CreateEdge(F, E, 82  ) );
    AddEdge( F, CreateEdge(F, G, 154 ) );
    AddEdge( F, CreateEdge(F, H, 120 ) );

    AddEdge( G, CreateEdge(G, C, 220 ) );
    AddEdge( G, CreateEdge(G, F, 154 ) );
    AddEdge( G, CreateEdge(G, I, 106 ) );

    AddEdge( H, CreateEdge(H, E, 98  ) );
    AddEdge( H, CreateEdge(H, F, 120 ) );

    AddEdge( I, CreateEdge(I, G, 106 ) );
    
    // 정점 B를 시작으로 하는 최소 신장 트리
    Dijkstra(graph, B, tree);
    PrintGraph(tree);
    
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

void PrintGraph(Graph* g)
{
    Vertex* v = NULL;
    Edge* e = NULL;
    
    if((v = g->vertices) == NULL) {
        return;
    }
    
    while(v != NULL) {
        printf("%c : ", v->data);
        
        if((e = v->adjacencyList) == NULL) {
            v = v->next;
            
            printf("\n");
            continue;
        }
        
        while(e != NULL) {
            printf("%c[%d] ", e->target->data, e->weight);
            e = e->next;
        }
        
        printf("\n");
        
        v = v->next;
    }
    
    printf("\n");
}

void Dijkstra(Graph* g, Vertex* startVertex, Graph* tree)
{
    int i = 0;
    
    Node startNode = { 0, startVertex };
    PriorityQueue* queue = CreateQueue(10);
    
    Vertex* currentVertex = NULL;
    Edge* currentEdge = NULL;
    
    int* weights = (int*)malloc(sizeof(int) * g->vertexCount);
    Vertex** treeVertices = (Vertex**) malloc(sizeof(Vertex*) * g->vertexCount);
    Vertex** fringes = (Vertex**) malloc(sizeof(Vertex*) * g->vertexCount);
    Vertex** precedences = (Vertex**) malloc(sizeof(Vertex*) * g->vertexCount);
    
    currentVertex = g->vertices;
    
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
        Node tempNode;
        
        Dequeue(queue, &tempNode);
        currentVertex = (Vertex*)tempNode.data;
        
        fringes[currentVertex->index] = currentVertex;
        
        currentEdge = currentVertex->adjacencyList;
        
        while(currentEdge != NULL) {
            Vertex* targetVertex = currentEdge->target;
            
            if(fringes[targetVertex->index] == NULL && weights[currentVertex->index] + currentEdge->weight < weights[targetVertex->index]) {
                Node newNode = { currentEdge->weight, targetVertex };
                Enqueue(queue, newNode);
                
                precedences[targetVertex->index] = currentEdge->from;
                weights[targetVertex->index] = weights[currentVertex->index] + currentEdge->weight;
            }
            
            currentEdge = currentEdge->next;
        }
    }
    
    for(i = 0; i < g->vertexCount; i++) {
        int fromIndex, toIndex;
        
        if(precedences[i] == NULL) {
            continue;
        }
        
        fromIndex = precedences[i]->index;
        
        toIndex = i;
        
        AddEdge(treeVertices[fromIndex], CreateEdge(treeVertices[fromIndex], treeVertices[toIndex], weights[i]));
    }
    
    free(fringes);
    free(precedences);
    free(treeVertices);
    DestroyQueue(queue);
}
