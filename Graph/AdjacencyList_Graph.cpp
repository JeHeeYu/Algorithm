#include <iostream>
#include <vector>

enum class visitMode
{
    Visited,
    NotVisited
};

struct Vertex
{
    int data;
    int visited;
    int index;
    
    Vertex* next;
    struct Edge* adjacencyList;
};

struct Edge
{
    int weight;
    struct Edge* next;
    Vertex* from;
    Vertex* target;
};

struct Graph
{
    Vertex* vertices;
    int vertexCount;
};

Graph* CreateGraph();
void DestroyGraph(Graph* g);

Vertex* CreateVertex(int data);
void DestroyVertex(Vertex* v);

Edge* CreateEdge(Vertex* from, Vertex* garget, int weight);
void DestroyEdge(Edge* e);

void AddVertex(Graph* g, Vertex* v);
void AddEdge(Vertex* v, Edge* e);
void PrintGraph(Graph* g);

using namespace std;

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
    Graph* graph = new Graph;
    graph->vertices = nullptr;
    graph->vertexCount = 0;
    
    return graph;
}

void DestroyGraph(Graph* g)
{
    // 다음 정점이 데이터가 있을 경우 반복해서 해제
    while(g->vertices != nullptr) {
        Vertex* vertices = g->vertices->next;
        DestroyVertex(g->vertices);
        g->vertices = vertices;
    }
    
    delete g;
}

Vertex* CreateVertex(int data)
{
    // 새로운 정점 생성
    Vertex* v = new Vertex;
    
    v->data = data;
    v->next = nullptr;
    v->adjacencyList = nullptr;
    v->visited = static_cast<int>(visitMode::NotVisited);
    v->index = -1;
    
    return v;
}

void DestroyVertex(Vertex* v)
{
    // 인접한 정점이 데이터가 있을 경우 반복해서 해제
    while(v->adjacencyList != nullptr) {
        Edge* edge = v->adjacencyList->next;
        DestroyEdge(v->adjacencyList);
        v->adjacencyList = edge;
    }
    
    delete v;
}

Edge* CreateEdge(Vertex* from, Vertex* target, int weight)
{
    // 새로운 간선 생성
    Edge* e = new Edge;
    
    e->from = from;
    e->target = target;
    e->weight = weight;
    
    return e;
}

void DestroyEdge(Edge* e)
{
    delete e;
}

void AddVertex(Graph* g, Vertex* v)
{
    Vertex* vertexList = g->vertices;
    
    if(vertexList == nullptr) {
        g->vertices = v;
    }
    else {
        while(vertexList->next != nullptr) {
            vertexList = vertexList->next;
        }
        
        vertexList->next = v;
    }
    
    v->index = g->vertexCount++;
}

void AddEdge(Vertex* v, Edge* e)
{
    if(v->adjacencyList == nullptr) {
        v->adjacencyList = e;
    }
    else {
        Edge* adjacencyList = v->adjacencyList;
        
        while(adjacencyList->next != nullptr) {
            adjacencyList = adjacencyList->next;
        }
        
        adjacencyList->next = e;
    }
}

void PrintGraph(Graph* g)
{
    Vertex* v = nullptr;
    Edge* e = nullptr;
    
    if((v = g->vertices) == nullptr) {
        return;
    }
    
    while(v != nullptr) {
        cout << " " << static_cast<char>(v->data) << " : ";
        
        if((e = v->adjacencyList) == nullptr) {
            v = v->next;
            
            cout << endl;
            continue;
        }
        
        while(e != nullptr) {
            cout << static_cast<char>(e->target->data) << "[" << e->weight << "] ";
            e = e->next;
        }
        
        cout << endl;
        
        v = v->next;
    }
    
    cout << endl;
}
