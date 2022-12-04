#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    // 왼쪽 자식을 가리키는 필드
    struct _Node* left;
    
    // 오른쪽 자식을 가리키는 필드
    struct _Node* right;
    
    // 데이터를 담는 필드
    char data;
} Node;

Node* CreateNode(char newData);
void DestroyNode(Node* node);
void PreorderPrintTree(Node* node);
void InorderPrintTree(Node* node);
void PostorderPrintTree(Node* node);
void DestroyTree(Node* node);

int main() 
{
    // 노드 생성
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');
    Node* F = CreateNode('F');
    Node* G = CreateNode('G');
    
    // 트리에 노드 추가
    A->left = B;
    B->left = C;
    B->right = D;
    
    A->right = E;
    E->left = F;
    E->right = G;
    
    // 전위 순회 방식 트리 출력
    printf("Preorder Tree\n");
    PreorderPrintTree(A);
    
    printf("\n\n");
    
    // 중위 순회 방식 트리 출력
    printf("Inorder Tree\n");
    InorderPrintTree(A);
    
    printf("\n\n");
    
    // 후위 순회 방식 트리 출력
    printf("Postorder Tree\n");
    PostorderPrintTree(A);
    
    printf("\n");
    
    DestroyTree(A);

    return 0;
}

Node* CreateNode(char newData)
{
    // 메모리 공간 할당
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 각 필드 초기화
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    
    // 노드의 메모리 주소 반환
    return newNode;
}

void DestroyNode(Node* node)
{
    free(node);
}

void PreorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
    
    // 왼쪽 하위 트리 출력
    PreorderPrintTree(node->left);
    
    // 오른쪽 하위 트리 출력
    PreorderPrintTree(node->right);
}

void InorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 왼쪽 하위 트리 출력
    InorderPrintTree(node->left);
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
    
    // 오른쪽 하위 트리 출력
    InorderPrintTree(node->right);
}

void PostorderPrintTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    // 왼쪽 하위 트리 출력
    PostorderPrintTree(node->left);
    
    // 오른쪽 하위 트리 출력
    PostorderPrintTree(node->right);
    
    // 뿌리 노드 출력
    printf(" %c", node->data);
}

void DestroyTree(Node* node)
{
    // 빈 노드일 경우
    if(node == NULL) {
        return;
    }
    
    DestroyTree(node->left);
    DestroyTree(node->right);
    DestroyNode(node);
}
