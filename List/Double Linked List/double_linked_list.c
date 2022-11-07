#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의

typedef struct tagNode
{
    ElementType data;             // 저장할 데이터
    struct tagNode* prevNode;     // 앞 노드의 주소와 데이터
    struct tagNode* nextNode;     // 뒤 노드의 주소와 데이터
} Node;

// 함수 원형
Node* DLL_CreateNode(ElementType newData);          // 노드 생성
void DLL_DestroyNode(Node* node);                   // 노드 소멸
void DLL_AppendNode(Node** head, Node* newHead);    // 노드 추가
void DLL_InsertAfter(Node* current, Node* newNode); // 노드 삽입
void DLL_InsertNewHead(Node** head, Node* newHead); // 헤드 삽입
void DLL_RemoveNode(Node** head, Node* removeNode);     // 노드 삭제
Node* DLL_GetNodeAt(Node* head, int location);      // 노드 탐색
int DLL_GetNodeCount(Node* head);                   // 노드 개수

int main()
{
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* newNode = NULL;
    Node* current = NULL;
    
    for(i = 0; i < 5; i++) {
        newNode = DLL_CreateNode(i);
        DLL_AppendNode(&list, newNode);
    }
    
    // 노드 개수 출력
    count = DLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        current = DLL_GetNodeAt(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }
    
    // 리스트의 세 번째 칸 뒤에 노드 삽입
    printf("\nInserting 3000 After [2]\n\n");
    
    count = DLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        current = DLL_GetNodeAt(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }
    
    // 모든 노드 소멸
    printf("Destroying List\n\n");
    
    count = DLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        current = DLL_GetNodeAt(list, 0);
        
        if(current != NULL) {
            DLL_RemoveNode(&list, current);
            DLL_DestroyNode(current);
        }
    }
    
    return 0;
}

// 노드 생성
Node* DLL_CreateNode(ElementType newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = newData;      // 저장할 데이터
    newNode->prevNode = NULL;     // 앞 노드의 정보
    newNode->nextNode = NULL;     // 뒤 노드의 정보
    
    return newNode;
}

// 노드 소멸
void DLL_DestroyNode(Node* node)
{
    free(node);
}

// 노드 추가
void DLL_AppendNode(Node** head, Node* newNode)
{
    // 헤드의 노드가 NULL일 경우 새로운 노드가 헤드가 됨
    if((*head) == NULL) {
        *head = newNode;
    }
    // 헤드의 노드가 NULL이 아닐 경우 테일을 찾아 NewNode를 연결
    else {
        // 테일에 연결
        Node* tail = (*head);
        
        while(tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        
        tail->nextNode = newNode;
        newNode->prevNode = tail;   // 기존의 테일을 새로운 테일의 prevNode가 가리킴
    }
}

// 노드 탐색
Node* DLL_GetNodeAt(Node* head, int location)
{
    Node* current = head;
    
    while(current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    
    return current;
    
}

// 노드Node
void DLL_RemoveNode(Node** head, Node* removeNode)
{
    if(*head == removeNode) {
        *head = removeNode->nextNode;
        
        if((*head) != NULL) {
            (*head)->prevNode = NULL;
        }
        
        // 삭제할 노드의 가리키고 있는 값 초기화
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    }
    else {
        Node* temp = removeNode;
        
        // 삭제할 노드의 prevNode 포인터가 가리키던 노드를 이전 노드의 nextNode 포인터가 가리키게 변경
        if(removeNode->prevNode != NULL) {
            removeNode->prevNode->nextNode = temp->nextNode;
        }
        
        // 삭제할 노드의 nextNode 포인터가 가리키던 노드를 이전 노드의 nextNode 포인터가 가리키게 변경
        if(removeNode->nextNode != NULL) {
            removeNode->nextNode->prevNode = temp->prevNode;
        }
        
        // 삭제할 노드의 가리키고 있는 값 초기화
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    }
}

// 노드 삽입
void DLL_InsertAfter(Node* current, Node* newNode)
{
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;
    
    if(current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;
    }
}

// 노드 개수
int DLL_GetNodeCount(Node* head)
{
    int count = 0;
    Node* current = head;
    
    while(current != NULL) {  
        current = current->nextNode;
        count++;
    }
    
    return count++;
}
