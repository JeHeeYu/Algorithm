## 요약
<ul>
<li>링크드 리스틀 이용하여 구현한 큐를 말함</li>
<li>필요한 큐의 크기를 미리 정하여 사용할 수 있고, 이에 따라 고성능이 요구되는 상황에서 유용</li>
<li>링크드 큐는 직관적으로 설계 및 구현이 가능한 큐로, 전단과 후단의 주소를 담고 있어야 </li>
</ul>

## 링크드 큐(Linked Queue)

링크드 큐는 큐의 특성을 지니고 있는 큐로, 링크드 리스틀 이용하여 큐를 구현한다.
<br>
원형 큐보다 직관적으로 구현할 수 있는 큐이다.
<br>
<br>
링크드 큐의 중요한 점은 노드 생성 및 삭제에 관한 malloc() 함수와 free() 함수를 호출하여 사용하지 않는다.
<br>
따라서 필요한 큐의 크기를 미리 정하여 사용할 수 있고, 이에 따라 고성능이 요구되는 상황에서 유용한 큐이다.

<br>
<br>
링크드 큐는 각 노드의 이전 노드에 대한 포인터를 이용해 연결되므로 삽입 연산과 제거 연산 시 포인터를 잘 신경써야 한다.

<ul>
<li>삽입 연산 : 삽입 하려는 노드에 후단을 연결</li>
<li>제거 연산 : 전단 바로 다음 노드에서 전단에 대한 포인터 제거</li>
</ul>

아래 내용이 링크드 큐에서 제거 연산이 이루어지는 과정이다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208285012-cf26410a-27c2-4650-a5be-4a90ca9fd3fd.png)

<br>

## 링크드 큐 구현
링크드 큐는 직관적으로 설계 및 구현이 가능한 큐로, 전단과 후단의 주소를 담고 있어야 한다.

## 링크드 큐 구조체
링크드 큐 구조체는 링크드 큐 구조체와 노드 구조체 총 2개로 이루어진다.
<br>
```
// 노드 구조체
typedef struct _Node
{
    char* data;             // 노드에 담을 데이터
    struct _Node* nextNode;     // 다음 노드에 대한 포인터
} Node;

// 링크드 큐 구조체
typedef struct _LinkedQueue
{
    Node* front;     // 전단을 가리킴
    Node* rear;      // 후단을 가리킴
    int count;       // 노드 개수
} LinkedQueue;
```

## 링크드 큐 생성
링크드 큐를 생성하기 위해 malloc 함수로 동적 메모리를 생성한다.
```
void CreateQueue(LinkedQueue** queue)
{
    // 큐 생성
    (*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    
    // 필드 초기화
    (*queue)->front = NULL;
    (*queue)->rear = NULL;
    (*queue)->count = 0;
}
```

## 링크드 큐 소멸
링크드 큐를 소멸시키기 위해 모든 노드를 제거하고 이후 큐도 제거한다.
```
void DestroyQueue(LinkedQueue* queue)
{
    // 노드가 있을 경우 삭제
    while(!IsEmpty(queue)) {
        Node* temp = Dequeue(queue);
        DestroyNode(temp);
    }
    
    // 큐 삭제
    free(queue);
}
```

## 노드 생성
노드를 생성하기 위해 동적 메모리를 생성하고, 이에 대한 주소를 반환한다.
```
Node* CreateNode(char* newData)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = (char*)malloc(strlen(newData) + 1);
    
    // 데이터 저장
    strcpy(newNode->data, newData);
    
    // 다음 노드에 대한 포인터는 NULL로 초기화
    newNode->nextNode = NULL;
    
    // 노드 주소 반환
    return newNode;
}
```

## 노드 소멸
노드를 메모리에서 소멸시키기 위해 노드의 데이터와 노드 자체도 소멸시킨다.
```
void DestroyNode(Node* node)
{
    free(node->data);
    free(node);
}
```

## 삽입 연산
링크드 큐에서 삽입 연산은 후단에 새로운 노드를 붙이는 것만으로 간단하게 구현할 수 있다.
```
void Enqueue(LinkedQueue* queue, Node* newNode)
{
    // 전단이 없는 경우 처음 노드 생성임
    if(queue->front == NULL) {
        queue->front = newNode;
        queue->rear = newNode;
        queue->count++;
    }
    // 다음 노드에 삽입할 노드 할당
    else {
        queue->rear->nextNode = newNode;
        queue->rear = newNode;
        queue->count++;
    }
}
```

## 제거 연산
제거 연산은 전단 뒤에 노드를 새로운 전단으로 만들고, 전단이었던 노드의 포인터를 호출자에 반환한다.
```
Node* Dequeue(LinkedQueue* queue)
{
    // 반환할 최상위 노드
    Node* front = queue->front;
    
    if(queue->front->nextNode == NULL) {
        queue->front = NULL;
        queue->rear = NULL;
    }
    // 전단 뒤에 있는 노드를 새로운 노드로 만듦
    else {
        queue->front = queue->front->nextNode;
    }
    
    queue->count--;
    
    return front;
}
```

## 노드 공백 상태 확인
노드의 공백 상태 확인을 위해 front의 여부만 확인하면 된다.
```
int IsEmpty(LinkedQueue* queue)
{
    return queue->front == NULL;
}
```


### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Queue/Linked%20Queue/LinkedQueue.c)

### 실행 결과
```
Queue Size : 4
Deque : abc
Deque : def
Deque : ghi
Deque : jkl
```
