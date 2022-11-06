# 더블 링크드 리스트 정리 내용

### 요약
<ul>
<li>링크드 리스트의 문제였던 탐색 문제를 개선한 링크드 리스트 자료구조</li>
<li>첫 데이터를 헤드, 끝 데이터를 테일, 각 데이터를 노드라고 부름</li>
<li>각 노드의 다음 노드 주소와 이전 노드 주소 양 방향을 관리</li>
<li>노드가 앞 뒤 양 방향을 다루므로 접근은 용이하나 삭제 등에서 각각 전부 삭제해 주어야 함</li>
<li>데이터의 접근이 어려우나, 생성, 소멸, 삭제 등은 쉬움</li>
</ul>

## 더블 링크드 리스트(Double Linked List)란
더블 링크드 리스트란 링크드 리스트의 탐색 기능을 개선한 자료구조이다.
<br>
기존 링크드 리스트에서 탐색을 하기 위해 헤드에서 테일 방향으로의 노드를 모두 거쳐야 했다.
<br>
이러한 불편함을 더블 링크드 리스트 구조에선 헤드 -> 테일 및 테일 -> 헤드 방향, 즉 양방향 탐색이 가능하도록 개선했다.
<br>
<br>
양방향 탐색이 가능한 이유는 노드의 구조가 변경되었기 때문이다.
<br>
링크드 리스트에서 노드가 다음 노드를 가리키는 포인터였다면, 더블 링크드 리스트의 노드는 자신의 앞에 있는 노드를 가리키는 포인터도 갖고 있다.
<br>
그래서 더블 링크드 리스트의 노드는 앞과 뒤 모두 이동이 가능하다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200158791-510741ed-3c48-404b-94ce-acfc312f1591.JPG" witdh="200" height="150">
<br>
<br>
이를 구조체로 선언하면 다음과 같이 선언할 수 있다.
<pre>
typedef int ElementType;

typedef struct tagNode
{
    ElementType data;             // 저장할 데이터
    struct tagNode* prevNode;     // 앞 노드의 주소와 데이터
    struct tagNode* nextNode;     // 뒤 노드의 주소와 데이터
} Node;
</pre>
위 구조체를 사용하여 노드를 구성할 경우 더블 링크드 리스트가 된다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200158891-e9326c7b-099a-4d0e-baa8-9620e8ab0a6c.JPG" witdh="300" height="150">
<br>
<br>

## 링크드 리스트의 주요 연산
링크드 리스트의 주요 연산은 두 종류로, 자료구조를 구축하기 위한 연산과 자료구조에 저장된 데이터를 활용하기 위한 연산이다
<br>
기존 링크드 리스트의 연산과 동일하다.
<ul>
  <li>노드 생성(CreatedNode) 및 소멸(DestroyNode)</li>
  <li>노드 추가(AppendNode)</li>
  <li>노드 탐색(GetNodeAt)</li>
  <li>노드 삭제(RemoveNode)</li>
  <li>노드 삽입(InsertAfter, InsertNewHead)</li>
</ul>
위 리스트 중 생성 및 소멸, 추가 삭제는 자료구조를 구축하기 위한 연산, 탐색은 활용 연산이다.
<br>
<br>

## 노드의 생성/소멸 연산
노드를 생성하기 위해 힙 메모리 영역에 데이터를 할당해야 한다.
<br>
지역 변수로 같이 데이터를 생성하면 함수가 종료되면서 스택에 있던 데이터는 소멸된다.
<pre>
// 노드 생성
Node* DLL_CreateNode(ElementType newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = newData;      // 저장할 데이터
    newNode->prevNode = NULL;     // 앞 노드의 정보
    newNode->nextNode = NULL;     // 뒤 노드의 정보
    
    return newNode;
}
</pre>
노드의 소멸시키는 방법은 free 함수로 간단하게 처리할 수 있다.
<pre>
// 노드 소멸

void DLL_Destroy(Node* node)
{
    free(node);
}
</pre>

## 노드 추가 연산
노드 추가는 테일 노드 뒤에 새로운 노드를 만들어 연결하는 연산이다.
<br>
싱글 링크드 리스트와 다르게 새로운 테일의 prevNode 포인터도 기존 테일의 주소를 가리키도록 해야한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200159071-dc970f12-0bef-4897-8ef0-4357be79313a.JPG" width="350" height="150">
<br>
<br>
DLL_CreateNode() 함수를 노드 생성 후 기존 테일의 노드를 가리키게 한다.
<br>
<pre>
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
</pre>
DLL_AppendNode 함수는 다음과 같이 사용할 수 있다.
<pre>
Node* list = NULL;

DLL_AppendNode(&list, DLL_CreateNode(117));
DLL_AppendNode(&list, DLL_CreateNode(119));
</pre>


## 노드 탐색 연산
링크드 리스트에서 노드에 접근하기 위해서는 헤드부터 다음 노드에 대한 포인터를 징검다리 삼아 모든 노드를 거쳐야 한다.
<br>
찾고자 하는 요소가 N번째에 있다면 N - 1개의 노드를 전부 거쳐야 하므로 비효울적이다.
<br>
이 경우가 링크드 리스트의 단점이며, 반대로 정적인 배열은 한 번에 거칠수 있으므로 반대의 개념이 된다.
<pre>
Node* DLL_GetNodeAt(Node* head, int location)
{
    Node* current = head;
    
    while(current != NULL && (--location) >= 0) {
        current = current->nextNode;
    }
    
    return current;
}
</pre>

## 노드 삭제 연산
더블 링크드 리스트에서 삭제할 노드는 양쪽 포인터 2개, 이전 노드의 nextNode 포인터, 다음 노드의 prevNode 포인터 4개를 삭제해야 한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200159238-56a3b359-aec6-4b24-8df7-16928193453b.JPG" width="450" height="250">
<br>
<br>
삭제할 노드의 nextNode 포인터가 가리키던 노드를 이전 노드의 nextNode 포인터가 가리키게 바꾸고,
<br>
삭제할 prevNode 포인터가 가리키던 노드를 다음 노드의 prevNode 포인터가 가리키게 바꾼다.
<br>
그리고 삭제할 노드의 nextNode와 prevNode는 NULL로 값을 초기화한다.
<pre>
void DLL_RemoveNode(Node** head, Node* remove)
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
</pre>

## 노드 삽입
노드 삽입은 노드와 노드 사이에 새로운 노드를 끼워 넣는 연산이다.
<br>
새로운 노드를 삽입할 때 prevNode 포인터로는 이전 노드를 가리키게 하고,
<br>
nextNode 포인터로는 다음 노드를 가리키게 한다.
<br>
그리고 이전 노드의 nextNode 포인터와 다음 노드의 prevNode 포인터는 새 노드를 가리키게 한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200159430-a5eb4941-b017-46f3-b2bb-0465daea2bc7.JPG" width="350" height="200">
<br>
<br>
<pre>
void DLL_InsertAfter(Node* current, Node* newNode)
{
    newNode->nextNode = current->nextNode;
    newNode->prevNode = current;
    
    if(current->nextNode != NULL) {
        current->nextNode->prevNode = newNode;
        current->nextNode = newNode;
    }
}
</pre>

## 노드 개수 세기
노드의 개수를 세는 연산은 링크드 리스트 내에 존재하는 모든 노드의 개수를 반환한다.
<pre>
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
</pre>
