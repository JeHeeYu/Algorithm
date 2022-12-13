#include <stdio.h>
#include <stdlib.h>

enum visitMode
{
    Visited,
    NotVisited
};

typedef struct _Vertex
{
    int data;
    int visited;
    int index;
    
    struct _Vertex* next;
    struct _Edge* adjacencyList;
} Vertex;

typedef struct _Edge
{
    int weight;
    struct _Edge* next;
    Vertex* from;
    Vertex* target;
} Edge;

typedef struct _Graph
{
    Vertex* vertices;
    int vertexCount;
} Graph;

Graph* CreateGraph();
void DestroyGraph(Graph * g);

Vertex* CreateVertex(int data);
void DestroyVertex(Vertex* v);

Edge* CreateEdge(Vertex* from, Vertex* garget, int weight);
void DestroyEdge(Edge* e);

void AddVertex(Graph* g, Vertex* v);
void AddEdge(Vertex* v, Edge* e);
void PrintGraph(Graph* g);

int main()
{
    // 그래프 생성
    Graph* g = CreateGraph();
    
    // 정점 생성
    Vertex* v1 = CreateVertex('1');
    Vertex* v2 = CreateVertex('2');
    Vertex* v3 = CreateVertex('3');
    Vertex* v4 = CreateVertex('4');
    Vertex* v5 = CreateVertex('5');
    
    // 그래프에 정점 추가
    AddVertex(g, v1);
    AddVertex(g, v2);
    AddVertex(g, v3);
    AddVertex(g, v4);
    AddVertex(g, v5);
    
    // 정점과 정점을 간선으로 잇기
    AddEdge(v1, CreateEdge(v1, v2, 0));
    AddEdge(v1, CreateEdge(v1, v3, 0));
    AddEdge(v1, CreateEdge(v1, v4, 0));
    AddEdge(v1, CreateEdge(v1, v5, 0));
    
    AddEdge(v2, CreateEdge(v2, v1, 0));
    AddEdge(v2, CreateEdge(v2, v3, 0));
    AddEdge(v2, CreateEdge(v2, v5, 0));
    
    AddEdge(v3, CreateEdge(v3, v1, 0));
    AddEdge(v3, CreateEdge(v3, v2, 0));
    
    AddEdge(v4, CreateEdge(v4, v1, 0));
    AddEdge(v4, CreateEdge(v4, v5, 0));
    
    AddEdge(v5, CreateEdge(v5, v1, 0));
    AddEdge(v5, CreateEdge(v5, v2, 0));
    AddEdge(v5, CreateEdge(v5, v4, 0));
    
    PrintGraph(g);
    
    DestroyGraph(g);

    return 0;
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
        return g->vertices = v;
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
        printf(" %c : ", v->data);
        
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
