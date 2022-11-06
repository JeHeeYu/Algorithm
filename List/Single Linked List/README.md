# Linked List

### 요약
<ul>
<li>배열의 반대 개념으로, 데이터의 크기를 유연하게 변경할 수 있음</li>
<li>첫 데이터를 헤드, 끝 데이터를 테일, 각 데이터를 노드라고 부름</li>
<li>다음 노드의 주소를 이전 노드의 저장하여 다음 노드의 주소로 접근</li>
<li>데이터의 접근이 어려우나, 생성, 소멸, 삭제 등은 쉬움</li>
</ul>

### 장점
<ul>
<li>새로운 노두의 추가, 삽입, 삭제가 쉽고 빠름. (배열은 새로운 요소를 삽입하거나 삭제를 하기 어려움)</li>
<li>현재 노드의 다음 노드를 얻어오는 연산에 대해 비용이 발생하지 않음</li>
</ul>

### 단점
<ul>
<li>다음 노드를 가리키려는 포인터 때문에 각 노드마다 추가적인 메모리가 필요함</li>
<li>특정 위치에 있는 노드에 접근하기 위한 비용이 크며 접근하기 까지 시간이 많이 필요함 (노드에 접근하기 위해 N - 1회의 접근이 필요함)</li>
</ul>

## 리스트란
리스트는 이름과 같이 목록 형태로 이루어진 데이터 형식을 말한다.
<br>
리스트의 목록을 이루는 개별 요소를 노드(node)라고 한다.
<br>
<br>
리스트의 첫 번째 노드를 헤드(Head), 마지막 노드를 테일(Tail)이라고 부르며 리스트의 길이는 헤드부터 테일까지의 노드 수이다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200107948-de6e7614-5c8d-459d-aaab-b152f830b81a.JPG" witdh="300" height="200">
<br>
<br>
리스트와 비슷한 데이터 형식으로 배열이 존재한다.
<br>
배열과 리스트의 차이는 배열은 생성 시 배열의 크기를 지정해 주어야 한다.(정적)
<br>
반면 리스트는 배열과 반대로 유연하게 크기를 바꿀 수 있다.(동적)
<br>
<br>
리스트의 구조는 링크드 리스트, 더블 링크드 리스트, 환형 링크드 리스트 등이 있다.
<br>
<br>

## 링크드 리스트(Linked List)
링크드 리스트란 <b>노드를 연결해서 만든 리스트</b>라고 한다.
<br>
링크드 리스트의 노드는 데이터를 보관하는 필드, 다음 노드와 연결 고리 역할을 하는 포인터로 이루어진다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200108364-b32a5d09-c707-4dfd-b03e-f1c782934c6a.JPG" witdh="200" height="100">
<img src="https://user-images.githubusercontent.com/87363461/200108435-704a72cf-ecb4-4f68-b73e-d2f7b9c749b9.JPG" witdh="700" height="100">
<br>
<br>
링크드 리스트는 포인터만 교환하면 노드 사이에 노드를 끼워 넣거나 제거하는 부분이 간단하게 이루어진다.
<br>
C언어에서 링크드 리스트는 다음과 같은 구조체로 나타낸다.
<pre>
typedef int ElementType;

typedef struct tagNode
{
    ElementType Data; // 데이터
    struct Node* NextNode; // 다음 노드
} Node;
</pre>

## 링크드 리스트의 주요 연산
링크드 리스트의 주요 연산은 두 종류로, 자료구조를 구축하기 위한 연산과 자료구조에 저장된 데이터를 활용하기 위한 연산이다
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
// 노드의= 생성

Node* SLL_CreateNode(ElementType NewData)
{
    Node* NewNode = (Node*)malloc(sizeof(Node));
    
    NewNode->Data = NewData;        // 데이터 저장
    NewNode->NextNode = NULL;       // 다음 노드에 대한 포인터 NULL 초기화
    
    return NewNode;                 // 노드의 주소 반환
}
</pre>
노드의 소멸시키는 방법은 free 함수로 간단하게 처리할 수 있다.
<pre>
// 노드 소멸

void SLL_Destroy(Node* Node)
{
    free(Node);
}
</pre>

## 노드 추가 연산
노드 추가는 링크드 리스트의 테일 노드 뒤에 새로운 노드를 만들어 연결하는 연산이다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200155671-d16daa60-1f23-43e0-87ea-fcdfbfffc4c2.JPG" width="350" height="150">
<br>
<br>
SLL_CreateNode() 함수를 이용하여 힙 메모리에 노드 생성 후 생성한 노드의 주소를 테일의 NextNode 포인터에 저장한다.
<br>
<pre>
void SLL_AppendNode(Node** Head, Node* NewNode)
{
    // 헤드의 노드가 NULL일 경우 새로운 노드가 헤드가 됨
    if((*Head) == NULL) {
        *Head = NewNode;
    }
    // 헤드의 노드가 NULL이 아닐 경우 테일을 찾아 NewNode를 연결
    eles {
        // 테일에 연결
        Node* Tail = (*Head);
        
        while(Tail->NextNode != NULL) {
            Tail = Tail->NextNode;
        }
        
        Tail->NextNode = NewNode;
    }
}
</pre>

## 노드 탐색 연산
링크드 리스트에서 노드에 접근하기 위해서는 헤드부터 다음 노드에 대한 포인터를 징검다리 삼아 모든 노드를 거쳐야 한다.
<br>
찾고자 하는 요소가 N번째에 있다면 N - 1개의 노드를 전부 거쳐야 하므로 비효울적이다.
<br>
이 경우가 링크드 리스트의 단점이며, 반대로 정적인 배열은 한 번에 거칠수 있으므로 반대의 개념이 된다.
<pre>
Node* SLL_GetNodeAt(Node* Head, int Location)
{
    Node* Current = Head;
    
    while(Current != NULL && (--Location) >= 0) {
        Current = Current->NextNode;
    }
    
    return Current;
}
</pre>

## 노드 삭제 연산
노드 삭제의 경우 삭제하고자 하는 노드를 찾고 다음 노드를 이전 노드의 NextNode 포인터에 연결하면 된다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200155930-627d088d-d1b0-4240-8d75-173980c198b2.JPG" width="350" height="150">
<br>
<br>
<pre>
void SLL_RemoveNode(Node** Head, Node* Remove)
{
    if(*Head == Remove) {
        *Head = Remove->NextNode;
    }
    else {
        Node* Current = *Head;
        while(Current != NULL && Current->NextNode != Remove) {
            Current = Current->NextNode;
        }
        
        if(Current != NULL) {
            Current->NextNode = Remove->NextNode;
        }
    }
}
</pre>

## 노드 삽입
노드 삽입은 노드와 노드 사이에 새로운 노드를 끼워 넣는 연산이다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200156021-4c31a405-f953-4375-be19-ae3fcd6ec5ee.JPG" width="350" height="200">
<br>
<br>
<pre>
void SLL_InsertAfter(Node* Current, Node* NewNode)
{
    NewNode->NextNpde = Current->NextNode;
    Current->NextNode = NewNode;
}
</pre>

## 노드 개수 세기
노드의 개수를 세는 연산은 링크드 리스트 내에 존재하는 모든 노드의 개수를 반환한다.
<pre>
int SLL_GetNodeCount(Node* Head)
{
    int Count = 0;
    Node* Current = Head;
    
    while(Current != NULL) {  
        Current = Current->NextNode;
        Count++;
    }
    
    return Count++;
}
</pre>
