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
Node* CDLL_CreateNode(ElementType newData);          // 노드 생성
void CDLL_DestroyNode(Node* node);                   // 노드 소멸
void CDLL_AppendNode(Node** head, Node* newHead);    // 노드 추가
void CDLL_InsertAfter(Node* current, Node* newNode); // 노드 삽입
void CDLL_InsertNewHead(Node** head, Node* newHead); // 헤드 삽입
void CDLL_RemoveNode(Node** head, Node* removeNode);     // 노드 삭제
Node* CDLL_GetNodeAt(Node* head, int location);      // 노드 탐색
int CDLL_GetNodeCount(Node* head);                   // 노드 개수

int main()
{
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* newNode = NULL;
    Node* current = NULL;
    
    for(i = 0; i < 5; i++) {
        newNode = CDLL_CreateNode(i);
        CDLL_AppendNode(&list, newNode);
    }
    
    // 노드 개수 출력
    count = CDLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        current = CDLL_GetNodeAt(list, i);
        printf("List[%d] : %d\n", i, current->data);
    }
    
    // 리스트의 세 번째 칸 뒤에 노드 삽입
    printf("\nInserting 3000 After [2]\n\n");
    
    current = CDLL_GetNodeAt(list, 2);
    newNode = CDLL_CreateNode(3000);
    CDLL_InsertAfter(current, newNode);
    
    printf("Removeing Node at 2...\n");
    
    current = CDLL_GetNodeAt(list, 2);
    CDLL_RemoveNode(&list, current);
    CDLL_DestroyNode(current);
    
    count = CDLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        if(i == 0) {
            current = list;
        }
        else {
            current = current->nextNode;
        }
        
        printf("List[%d] : %d\n", i, current->data);
    }
    
    // 모든 노드 소멸
    printf("Destroying List\n\n");
    
    count = CDLL_GetNodeCount(list);
    
    for(i = 0; i < count; i++) {
        current = CDLL_GetNodeAt(list, 0);
        
        if(current != NULL) {
            CDLL_RemoveNode(&list, current);
            CDLL_DestroyNode(current);
        }
    }
    
    return 0;
}

// 노드 생성
Node* CDLL_CreateNode(ElementType newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = newData;      // 저장할 데이터
    newNode->prevNode = NULL;     // 앞 노드의 정보
    newNode->nextNode = NULL;     // 뒤 노드의 정보
    
    return newNode;
}

// 노드 소멸
void CDLL_DestroyNode(Node* node)
{
    free(node);
}

// 노드 추가
void CDLL_AppendNode(Node** head, Node* newNode)
{
    // 헤드 노드가 NULL이라면 새로운 노드가 헤드가 됨
    if((*head) == NULL) {
        *head = newNode;
        (*head)->nextNode = *head;
        (*head)->prevNode = *head;
    }
    else {
        // 테일과 헤드 사이에 newNode 삽입
        Node* tail = (*head)->prevNode;
        
        tail->nextNode->prevNode = newNode;
        tail->nextNode = newNode;
        
        newNode->nextNode = (*head);
        newNode->prevNode = tail;   // 새로운 테일의 prevNode가 기존의 테일을 가리킴
    }
}

// 노드 탐색
Node* CDLL_GetNodeAt(Node* head, int location)
{
    Node* current = head;
    
    while(current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    
    return current;
    
}

// 노드Node
void CDLL_RemoveNode(Node** head, Node* removeNode)
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
void CDLL_InsertAfter(Node* current, Node* newNode)
{
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;
    
    if(current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;
    }
}

// 노드 개수
int CDLL_GetNodeCount(Node* head)
{
    int count = 0;
    Node* current = head;
    
    while(current != NULL) {  
        current = current->nextNode;
        count++;
    }
    
    return count++;
}
