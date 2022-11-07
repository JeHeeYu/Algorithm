#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

// 노드 구조체 정의
typedef struct tagNode
{
    ElementType data;
    struct tagNode* nextNode;
} Node;

// 함수 원형
Node* SLL_CreateNode(ElementType NewData);          // 노드 생성
void SLL_DestroyNode(Node* Node);                   // 노드 소멸
void SLL_AppendNode(Node** Head, Node* NewHead);    // 노드 추가
void SLL_InsertAfter(Node* Current, Node* NewNode); // 노드 삽입
void SLL_InsertNewHead(Node** Head, Node* NewHead); // 헤드 삽입
void SLL_RemoveNode(Node** Head, Node* Remove);     // 노드 삭제
Node* SLL_GetNodeAt(Node* Head, int Location);      // 노드 탐색
int SLL_GetNodeCount(Node* Head);                   // 노드 개수

int main()
{
    int i = 0;
    int count = 0;
    Node* list = NULL;
    Node* current = NULL;
    Node* newNode = NULL;
    
    for(i = 0; i < 5; i++) {
        newNode = SLL_CreateNode(i);
        SLL_AppendNode(&list, newNode);
    }
    
    newNode = SLL_CreateNode(-1);
    SLL_InsertNewHead(&list, newNode);
    
    newNode = SLL_CreateNode(-2);
    SLL_InsertNewHead(&list, newNode);
    
    // 노드 리스트 출력
    count = SLL_GetNodeCount(list);
    for(i = 0; i < count; i++) {
        current = SLL_GetNodeAt(list, i);
        printf("List : [%d] : %d\n", i, current->data);
    }
    
    // 리스트의 세 번째 노드 뒤에 새 노드 삽입
    printf("\nInserting 3000 After [2]...\n\n");
    
    current = SLL_GetNodeAt(list, 2);
    newNode = SLL_CreateNode(3000);
    
    SLL_InsertAfter(current, newNode);
    
    // 노드 리스트 출력
    for(i = 0; i < count; i++) {
        current = SLL_GetNodeAt(list ,i);
        printf("List[%d] : %d\n", i, current->data);
    }
    
    // 모든 노드 소멸
    printf("\nDestroying List...\n");
    
    for(i = 0; i < count; i++) {
        current = SLL_GetNodeAt(list ,0);
        
        if(current != NULL) {
            SLL_RemoveNode(&list, current);
            SLL_DestroyNode(current);
        }
    }
    
    return 0;
}

// 노드 생성
Node* SLL_CreateNode(ElementType newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    
    newNode->data = newData;    // 데이터 저장
    newNode->nextNode = NULL;   // 다음 노드에 대한 포인터 NULL로 초기화
    
    return newNode;     // 노드 주소 반환
}

// 노드 소멸
void SLL_DestroyNode(Node* node)
{
    free(node);
}

// 노드 추가
void SLL_AppendNode(Node** head, Node* newNode)
{
    // 헤드 노드가 NULL일 경우 새로운 헤드 생성
    if((*head) == NULL) {
        *head = newNode;
    }
    else {
        // 헤드가 존재할 경우 테일을 찾아 NewNode를 연결
        Node* tail = (*head);
        while(tail->nextNode != NULL) {
            tail = tail->nextNode;
        }
        
        tail->nextNode = newNode;
    }
}

// 노드 삽입
void SLL_InsertAfter(Node* current, Node* newNode)
{
    newNode->nextNode = current->nextNode;
    current->nextNode = newNode;
}

// 헤드 삽입
void SLL_InsertNewHead(Node** head, Node* newHead)
{
    if(head == NULL) {
        (*head) = newHead;
    }
    else {
        newHead->nextNode = (*head);
        (*head) = newHead;
    }
}

// 노드 제거
void SLL_RemoveNode(Node** head, Node* removeNode)
{
    if(*head == removeNode)
    {
        *head = removeNode->nextNode;
    }
    else {
        Node* current = *head;
        while(current != NULL && current->nextNode != removeNode) {
            current = current->nextNode;
        }
        
        if(current != NULL) {
            current->nextNode = removeNode->nextNode;
        }
    }
}

// 노드 탐색
Node* SLL_GetNodeAt(Node* head, int location)
{
    Node* current = head;
    
    // 다음 노드 주소 탐색
    while(current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    
    return current;
}

// 노드 개수
int SLL_GetNodeCount(Node* head)
{
    int count = 0;
    Node* current = head;
    
    // 다음 노드가 NULL이 아닐 경우 카운트 1씩 증가
    while(current != NULL) {
        current = current->nextNode;
        count++;
    }
    
    return count;
}
