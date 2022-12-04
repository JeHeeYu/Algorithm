#include <stdio.h>
#include <stdlib.h>
 
typedef struct _Node
{
    struct _Node* child;
    struct _Node* sibling;
    
    char data;
} Node;

Node* CreateNode(char newData);
void DestroyNode(Node* node);
void AddChildNode(Node* parent, Node* child);
void PrintTree(Node* node, int depth);

int main() 
{
    // 루트 노드 생성
    Node* rootNode = CreateNode('A');    
    
    // 노드 생성
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');
    Node* F = CreateNode('F');
    Node* G = CreateNode('G');
    Node* H = CreateNode('H');
    Node* I = CreateNode('I');
    Node* J = CreateNode('J');
    Node* K = CreateNode('K');
    
    // 루트 노드 자식에 B노드 연결
    AddChildNode(rootNode, B);
    
    // B노드 자식에 C노드 연결 
    AddChildNode(B, C);
    
    // B노드 자식에 D노드 연결, C노드와 형제
    AddChildNode(B, D);
    
    // D노드 자식에 E노드 연결
    AddChildNode(D, E);
    
    // D노드 자식에 F노드 연결, E노드와 형제
    AddChildNode(D, F);
    
    // 루트 노드 자식에 G노드 연결, B노드와 형제
    AddChildNode(rootNode, G);
    
    // G노드 자식에 H노드 연결
    AddChildNode(G, H);
    
    // 루트 노드 자식에 I노드 연결, B노드, G노드와 형제
    AddChildNode(rootNode, I);
    
    // I노드 자식에 J노드 연결
    AddChildNode(I, J);
    
    // J노드 자식에 K노드 연결
    AddChildNode(J, K);
    
    // 노드 출력
    PrintTree(rootNode, 0);
    
    // 노드 소멸
    DestroyNode(rootNode);

    return 0;
}

Node* CreateNode(char newData)
{
    // 노드 구조체 크기만큼 동적 메모리 할당
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 루트 노드 생성
    newNode->child = NULL;
    newNode->sibling = NULL;
    newNode->data = newData;
    
    // 메모리 주소 반환
    return newNode;
}

void DestroyNode(Node* node)
{
    // 동적 메모리 할당 해제
    free(node);
}

void AddChildNode(Node* parent, Node* child)
{
    // 자식이 하나도 없으므로 바로 연결
    if(parent->child == NULL) {
        parent->child = child;
    }
    
    // 자식이 있는 경우
    else {
        // 기존 있던 자식 노드
        Node* tempNode = parent->child;
        
        // 가장 오른쪽에 있는 자식 노드를 찾을 때까지 반복
        while(tempNode->sibling != NULL) {
            tempNode = tempNode->sibling;
        }
        
        tempNode->sibling = child;
    }
}

void PrintTree(Node* node, int depth)
{
    // 공백 3칸을 사용하여 들여쓰기
    int i = 0;
    for(i = 0;i < depth - 1; i++) {
        printf("   ");
    }
    
    // 노드 자식 여부 표시
    if(depth > 0) {
        printf("+--");
    }
    
    // 노드 데이터 출력
    printf("%c\n", node->data);
    
    // 왼쪽 자식이 존재할 경우 재귀 반복
    if(node->child != NULL) {
        PrintTree(node->child, depth+1);
    }
    
    // 오른쪽 형제가 존재할 경우 재귀 반복
    if(node->sibling != NULL) {
        PrintTree(node->sibling, depth);
    }
}
