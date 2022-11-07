# 환형 링크드 리스트(Circular Linked List)

### 요약
<ul>
<li>더블 링크드 리스트와 동일하며, 다른 점은 헤드와 테일이 연결되어 있음</li>
<li>테일은 자신의 nextNode로 헤드를 가리키고, 헤드는 prevNode로 테일을 가리킴</li>
<li>리스트의 시작과 끝을 미리 알 수 있음</li>
</ul>

## 환형 링크드 리스트(Circular Linked List)란
환현 링크드는 헤드와 테일이 연결되어 있는 리스트 구조를 말한다.
<br>
테일은 자신의 nextNode로 헤드를 가리키고, 헤드는 prevNode로 테일을 가리킨다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200290277-2ce397c2-bea9-49c3-9a47-e3976ff7df72.JPG" width="400" height="150">
<br>
<br>
환형 링크드 리스트의 가장 큰 장점은 리스트의 시작과 끝을 미리 알 수 있다는 부분이다.
<br>
<br>
이러한 장점으로, 더블 링크드의 삽입 함수와 같은 부분의 성능을 많이 개선할 수 있다.
<br>
또한 노드를 뒤에서 역순으로 찾아나갈 수 있는 탐색도 구현할 수 있다.

## 환형 더블 링크드의 주요 연산
환형 링크드의 주요 연산 부분은 추가 연산과 삭제 연산으로, 이외의 함수들은 링크드 리스트와 더블 링크드 리스트 함수와 동일하다.
<br>
링크드 리스트와 더블 링크드 리스트 글 참조.

# 노드 추가 연산
환형 더블 링크드 연산에서 처음 추가된 새로운 노드는 새로운 헤드가 되고, 헤드의 이전 노드는 다시 헤드가 되며,
<br>
헤드의 다음 노드 역시 헤드 자신이 된다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200291184-a8b1d8b7-be79-42ca-a18b-e6835c06a6cf.JPG" width="350" height="150">
<br>
<br>
즉, 리스트가 비어 있지 않은 경우의 추가 연산 과정을 위해 <b>테일과 헤드 사이에 새 노드를 삽입한다.<b>라고 볼 수 있다.
<pre>
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
</pre>

### 노드 삭제 연산
<pre>
void CDLL_RemoveNode(Node** head, Node* removeNode)
{
    if(*head == removeNode) {
        (*head)->prevNode->nextNode = removeNode->nextNode;
        (*head)->nextNode->prevNode = removeNOde->prevNode;
        
        *head = removeNode->nextNode;
        
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    }
    else {
        removeNode->prevNode->nextNode = removeNode->nextNode;
        removeNode->nextNode->prevNode = removeNode->prevNode;
        
        removeNode->prevNode = NULL;
        removeNode->nextNode = NULL;
    }
}
</pre>
