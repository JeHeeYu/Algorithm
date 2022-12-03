#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    struct _Node* left;
    struct _Node* right;
    int data;
} Node;

// 새로운 노드 생성
Node* CreateNode(int newData);

// 노드 삭제
void DestroyNode(Node* node);

// 트리 삭제
void DestoryTree(Node* tree);

Node* SearchNode(Node* tree, int target);
Node* SearchMinNode(Node* tree);
void InsertNode(Node* tree, Node* child);
Node* RemoveNode(Node* tree, Node* parent, int target);
void InorderPrintTree(Node* Node);
void PrintSearchResult(int target, Node* result);

int main() 
{
        // 신규 트리 및 노드 생성
    Node* tree = CreateNode(123);
    Node* node = NULL;
    
    // 트리에 노드 추가
    InsertNode(tree, CreateNode(22));
    InsertNode(tree, CreateNode(9918));
    
    InsertNode(tree, CreateNode(424));
    InsertNode(tree, CreateNode(17));
    InsertNode(tree, CreateNode(3));
    
    InsertNode(tree, CreateNode(98));
    InsertNode(tree, CreateNode(34));
    
    InsertNode(tree, CreateNode(760));
    InsertNode(tree, CreateNode(317));
    InsertNode(tree, CreateNode(1));

    int target = 17;
    
    node = SearchNode(tree, target);
    PrintSearchResult(target, node);
    
    target = 117;
    node = SearchNode(tree, target);
    PrintSearchResult(target, node);
    
    // 트리 출력
    InorderPrintTree(tree);
    
    // 특정 노드 삭제
    printf("\nRemove 98 Node\n");
    
    node = RemoveNode(tree, NULL, 98);
    DestroyNode(node);
    
    InorderPrintTree(tree);
    printf("\n");
    
    // 신규 노드 삽입
    printf("Insert 111 Node\n");
    
    InsertNode(tree, CreateNode(111));
    InorderPrintTree(tree);
    
    // 트리 제거
    DestoryTree(tree);
    
    return 0;
}

Node* CreateNode(int newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // 루트 노드 생성 및 왼쪽 오른쪽 초기화
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = newData;
    
    return newNode;
}

void DestoryNode(Node* node)
{
    free(node);
}

void DestroyTree(Node* tree)
{
    // 오른쪽 하위 트리가 있을 경우 재귀 호출하여 오른쪽 하위 트리 삭제
    if(tree->right != NULL) {
        DestroyTree(tree->right);
    }
    
    // 왼쪽 하위 트리가 있을 경우 재귀 호출하여 왼쪽 하위 트리 삭제
    if(tree->left != NULL) {
        DestroyTree(tree->left);
    }
    
    // 모든 트리 삭제
    tree->left = NULL;
    tree->right = NULL;
    
    // 루트 노드 삭제
    DestroyNode(tree);
}

Node* SearchNode(Node* tree, int target)
{
    // 빈 트리일 경우
    if(tree == NULL) {
        return NULL;
    }
    
    // 노드의 값을 찾았을 경우
    if(tree->data == target) {
        return tree;
    }
    
    // 데이터가 찾고자 하는 값보다 낮을 경우, 왼쪽 하위 트리 탐색
    else if(tree->data > target) {
        return SearchNode(tree->left, target);
    }
    
    // // 데이터가 찾고자 하는 값보다 클 경우, 오른쪽 하위 트리 탐색
    else {
        return SearchNode(tree->right, target);
    }
}

Node* SearchMinNode(Node* tree)
{
    // 빈 트리일 경우
    if(tree == NULL) {
        return NULL;
    }
    
    // 왼쪽 자식이 없을 경우, 즉 가장 작은 값일 경우
    if(tree->left == NULL) {
        return tree;
    }
    
    // 왼쪽 하위 노드를 계속해서 탐색
    else {
        return SearchMinNode(tree->left);
    }
}

void InsertNode(Node* tree, Node* child)
{
    // 중앙 요소 노드가 넣고자 하는 노드보다 작을 때, 즉 큰 값의 경우
    if(tree->data < child->data) {
        
        // 트리의 가장 오른쪽에 삽입
        if(tree->right == NULL) {
            tree->right = child;
            
        } 
        
        // 트리의 가장 오른쪽까지 재귀
        else {
          InsertNode(tree->right, child);
            
        }
    }
    
    // 중앙 요소 노드가 넣고자 하는 노드보다 클 때, 즉 작은 값의 경우
    else if(tree->data > child->data) {
        
        // 트리의 가장 왼쪽에 삽입
        if(tree->left == NULL) {
            tree->left = child;
        }
        
        // 트리의 가장 왼쪽까지 재귀
        else {
            InsertNode(tree->left, child);
        }
    }
}

Node* RemoveNode(Node* tree, Node* parent, int target)
{
    Node* removeNode = NULL;
    
    // 빈 트리일 경우
    if(tree == NULL) {
        return NULL;
    }
    
    // 삭제할 값보다 클 경우 왼쪽 하위 트리 계속 탐색
    if(tree->data > target) {
        removeNode = RemoveNode(tree->left, tree, target);
    }
    
    // 삭제할 값보다 작을 경우 오른쪽 하위 트리 게속 탐색
    else if(tree->data < target) {
        removeNode = RemoveNode(tree->right, tree, target);
    }
    
    // 목표 값을 찾은 경우
    else {
        removeNode = tree;
        
        // Leaf 노드인 경우 바로 삭제
        if(tree->left == NULL && tree->right == NULL) {
            if(parent->left == tree) {
                parent->left = NULL;
            }
            else {
                parent->right = NULL;
            }
        }
        
        else {
            // 자식이 양쪽에 다 있는 경우
            if(tree->left != NULL && tree->right != NULL) {
                // 최솟값 노드를 찾아 제거 후 현재 노드에 위치 시킴
                Node* minNode = SearchMinNode(tree->right);
                
                minNode = RemoveNode(tree, NULL, minNode->data);
                
                tree->data = minNode->data;
            }
            
            else {
                // 자식이 한쪽만 있는 경우
                Node* temp = NULL;
                
                // 자식이 왼쪽일 경우
                if(tree->left != NULL) {
                    temp = tree->left;
                }
                // 자식이 오른쪽일 경우
                else {
                    temp = tree->right;
                }
                
                // 부모 위치에 따라 값 교환
                if(parent->left == tree) {
                    parent->left = temp;
                }
                else {
                    parent->right = temp;
                }
            }
        }
    }
    
    return removeNode;
}

void InorderPrintTree(Node* node)
{
    // 빈 트리일 경우
    if(node == NULL) {
        return;
    }
    
    // 왼쪽 하위 트리 출력
    InorderPrintTree(node->left);
    
    // 루트 노드 출력
    printf("%d ", node->data);
    
    // 오른쪽 하위 노드 출력
    InorderPrintTree(node->right);
}

void PrintSearchResult(int target, Node* result)
{
    if(result != NULL) {
        printf("찾은 노드 : %d \n", result->data);
    }
    else {
        printf("노드가 없습니다. %d\n", target);
    }
}
