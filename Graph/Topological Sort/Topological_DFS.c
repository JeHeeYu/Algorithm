// Online C compiler to run C program online
#include <stdio.h>

// 정점 방문 여부로 방문 : 0, 미방문 : 1
enum 
{
    VISITED,
    NOTVISITED
};

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

typedef struct _Node
{
    Vertex* data;
    struct _Node* nextNode;
} Node;

// 그래프 생성
Graph* createGraph();

// 그래프 제거
DestroyGraph(Graph* g);

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
void RemoveNode(Node** head, Node* remove);

// 노드 확인
Node* GetNode(Node* head, int location);

// 노드 개수 확인
int GetNodeCount(Node* head);

// 위상 정렬
void TopologicalSort(Vertex* v, Node** list);

// DFS를 이용한 위상 정렬
void DFS(Vertex* v, Node** list);

int main() {
    // Write C code here
    printf("Hello world");

    return 0;
}

// 그래프 생성
Graph* createGraph()
{
    
}

// 그래프 제거
DestroyGraph(Graph* g)
{
    
}

// 정점 추가
Vertex* CreateVertex(int data)
{
    
}

// 정점 제거
void DestroyVertex(Vertex* v)
{
    
}

// 정점 추가
void AddVertex(Graph* g, Vertex* v)
{
    
}

// 간선 추가
Edge* CreateEdge(Vertex* from, Vertex* target, int weight)
{
    
}

// 간선 제거
void DestroyEdge(Edge* e)
{
    
}

// 간선 추가
void AddEdge(Vertex* v, Edge* e)
{
    
}

// 그래프 출력
void PrintGraph(Graph* g)
{
    
}


// 노드 생성
Node* CreateNode(Vertex* newData)
{
    // 노드  메모리 생성
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 데이터 저장
    newNode->data = newData;
    
    // 다음 노드가 아직 없으므로 다음 노드에 대한 포인터는 NULL로 초기화
    newNode->nextNode = NULL;
    
    // 노드 주소 반환
    return newNode;
}

// 노드 제거
void DestroyNode(Node* node)
{
    // 노드 제거
    free(node);
}

// 노드 추가
void AppendNode(Node** head, Node* newNode)
{
    // 헤드 노드가 NULL일 경우 헤드가 없으므로 새로운 노드가 헤드가 됨
    if((*head) == NULL) {
        *head = newNode;
    }
    else {
        // 테일을 찾은 후 newNode를 연결
        Node* tail = (*head);
        while(tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        
        // 마지막 테일 뒤에 newNode 연결
        tail->nextNode = newNode;
    }
}

// 노드 삽입
void InsertNode(Node* current, Node* newNode)
{
    // 새로운 노드를 삽입할 노드의 뒤로 연결
    newNode->nextNode = current->nextNode;
    
    // 삽입할 노드의 뒤에 새로운 노드 연결
    current->nextNode = newNode;
}

// 헤드 삽입
void InsertHead(Node** head, Node* newHead)
{
    // 헤드 노드가 NULL일 경우 헤드가 없으므로 새로운 노드가 헤드가 됨
    if(head == NULL) {
        (*head) = newHead;
    }
    
    else {
        // 리스트의 헤드에 헤드 추가
        newHead->nextNode = (*head);
        (*head) = newHead;
    }
}

// 노드 삭제
void RemoveNode(Node** head, Node* remove)
{
    if(*head == remove) {
        *head = remove->nextNode;
    }
    else {
        Node* current = *head;
        
        while(current != NULL && current->nextNode != remove) {
            current = current->nextNode;
        }
        
        if(current != NULL) {
            current->nextNode = remove->nextNode;
        }
    }
}

// 노드 확인
Node* GetNode(Node* head, int location)
{
    
}

// 노드 개수 확인
int GetNodeCount(Node* head)
{
    
}

// 위상 정렬
void TopologicalSort(Vertex* v, Node** list)
{
    
}

// DFS를 이용한 위상 정렬
void DFS(Vertex* v, Node** list)
{
    
}
