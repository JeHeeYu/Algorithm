## 요약
<ul>
    <li>원형 큐란 기본(선형) 큐의 특성을 갖고 있으며, 큐에서 전단과 후단이 연결되어 있는 큐 구조임</li>
    <li>일반 큐의 경우 요소 이동 비용이 크지만, 원형 큐의 경우는 이 문제가 해결됨</li>
    <li>큐의 후단을 가리키는 변수는 전체 큐 크기의 + 1 </li>
    <li>전단과 후단의 값이 같을 경우 큐는 포화 상태임</li>
</ul>

## 원형 큐(Circular Queue)
원형 큐란 기본 선형 큐의 FIFO(First-In First-Out) 특성을 갖고 있는 큐에서 전단과 후단이 연결되어 있는 큐 구조를 말한다.
<br>
일반 큐 구조에서 제거 연산이 일어날 경우 데이터의 제거가 일어날 경우가 문제인데, 제거할 때 나머지 요소들을 앞으로 한 칸씩 옮겨야 한다. 이때 드는 비용이 상당히 만이 들어서 문제가 발생한다.
<br>
<br>
만약 큐 용량이 100일 경우, 제거를 한번 했는데도 99번의 이동 작업을 수행해야 하여 많이 비효율 적이다.
<br>
<br>
이 문제를 해결하기 위해 원형 큐를 사용하는데, 전단을 가리키는 변수를 도입해서 배열 내 요소를 옮기는 대신 전단의 위치만 변경하여 사용한다.
<br>
<br>
이와 함께 후단을 가리키는 변수도 생성해서 삽입이 일어날 때마다 후단의 위치를 변경한다.
<br>
이때 후단을 가리키는 변수는 실제 후단의 위치 + 1 한 값을 담아야 한다.
<br>
<br>
아래 큐가 바로 원형큐를 나타내는 큐다.
<br>

![캡처](https://user-images.githubusercontent.com/87363461/207783644-8e5f33f2-075d-4ed8-a315-b8353d320bba.PNG)

<br>
이 큐를 배열로 생각해보자.
<br>

![캡처](https://user-images.githubusercontent.com/87363461/207783985-1e734819-57f0-459d-a0b9-3ac0ea197107.PNG)

<br>

배열의 마지막 요소가 후단이었을 때 8을 삽입했고, 이로 인해 배열의 첫 번째 요소가 후단이 된다.
<br>
이 상태에서다시9를 삽입, 배열의 두 번째 요소가 후단이 되었다.
<br>
<br>
여기서 삽입이 이루어질 때마다 후단이 뒤로 후퇴하다가 전단을 만나면 큐는 가득 찬 상태가 된다.
<br>
<br>
큐가 가득 찼을 경우 삭제가 일어나지 않는 이상 추가적인 삽입은 불가능하다.
<br>
<br>
아래 그림이 위 설명을 표현한 그림이다.
<br>

## 공백 상태와 포화 상태
원형 큐가 제대로 동작하기 위해 큐가 공백 상태인지, 포화 상태인지 체크해야 한다.
<br>
공백 상태와 포화 상태를 체크하는 이유는 바로 전단과 후단이 같은 위치에 있어 만나기 때문이다.
<br>

![캡처](https://user-images.githubusercontent.com/87363461/207784387-2c98b94e-c2f3-4425-9e16-0d1faa7fbeff.PNG)

<br>

이 문제를 간단하게 해결하기 위해서 일반적으로 큐를 생성할 때 실제 용량보다 1만큼 더 크게 만든다.
<br>
그리고 전단과 후단(실제로는 후단) 사이를 비워두는 것이다.
<br>
<br>
이렇게 하면 큐가 공백 상태일 때 전단과 후단이 같은 곳을 가리키고, 큐가 포화 상태일 경우 후단이 전보다 1값이 작으므로 상태 구분이 용이해진다.
<br>

![캡처](https://user-images.githubusercontent.com/87363461/207784536-cd5a0277-951c-4292-b0c9-8caef504dc4a.PNG)

<br>

## 원형 큐 구현하기
배열을 기반으로 구현한 원형 큐 예제이다.

## 원형 큐 구조체
```
typedef struct _Node
{
    int data;
} Node;

typedef struct _CircleQueue
{
    int capacity; // 큐의 용량
    int front;    // 전단 위치
    int rear;     // 후단 위치
    
    Node* node;   // 요소 데이터
} CircularQueue;
```
여기서 주의해야 할 점은 rear의 크기는 실제 후단 + 1의 값을 갖는다는 점이다.

## 원형 큐 생성
```
void CreateQueue(CircularQueue** queue, int capacity)
{
    (*queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
    
    // 크기 1만큼 +해서 메모리 생성
    (*queue)->node = (Node*)malloc(sizeof(Node) * (capacity + 1));
    
    (*queue)->capacity = capacity;
    (*queue)->front = 0;
    (*queue)->rear = 0;
}
```
큐 생성 함수로, 원형 큐에 대한 포인터 queue와 용량을 정하는 capacity를 매개 변수로 받는다.
<br>
이후 메모리에 동적 할당하여 Node 크기 * (capacity + 1) 만큼 생성한다.

##  원형 큐 소멸
```
void DestroyQueue(CircularQueue* queue)
{
    // 원형 큐가 가리키는 노드 소멸
    free(queue->node);
    
    // 원형 큐 소멸
    free(queue);
}
```
소멸은 간단하게 free 함수를 이용하여 원형 큐와 원형 큐가 기리키는 노드 둘 다 소멸시킨다.

## 삽입 연산
```
void Enqueue(CircularQueue* queue, int data)
{
    // 후단 위치를 가리킬 변수
    int position = 0;
    
    // 후단이 큐 끝에 도달한 경우
    if(queue->rear == queue->capacity) {
        position = queue->rear;
        queue->rear = 0;
    }
    // 큐가 가득 차지 않았을 때
    else {
        // 현재 위치 1씩 증가
        position = queue->rear;
        queue->rear++;
    }
    
    queue->node[position].data = data;
}
```
원형 큐에서 삽입 연산은 후단의 위치를 가리키는 rear 변수를 다루는 것이 핵심이다.
<br>
rear의 값이 *queue->capacity + 1과 같은 값이라면, 후단이 큐 끝에 도달(큐가 가득 찬)한 의미로, rear와 position을 0으로 지정한다.
<br>
<br>
그렇지 않을 경우(큐의 메모리가 가득 차지 않은 경우) 현재 rear의 위치를 position에 저장하고 rear의 값을 1 증가시킨다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208222861-9ed59f4d-6d14-4210-b232-817bcf97d86c.png)

<br>

## 제거 연산
```
int Dequeue(CircularQueue* queue)
{
    // 전단 위치를 가리킬 변수
    int position = queue->front;
    
    // 전단이 큐 끝에 도달한 경우
    if(queue->front == queue->capacity) {
        queue->front;
    }
    else {
        queue->front++;   
    }
    
    return queue->node[position].data;
}
```
제거 연산에서는 rear가 아닌 front를 잘 관리하여야 한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/208223001-2e4f57b7-387b-4fb9-8eef-4881f1c69ba3.png)

<br>

## 공백 상태 확인
```
int IsEmpty(CircularQueue* queue)
{
    return (queue->front == queue->rear);
}
```
원형 큐가 비어있는지 확인하기 위한 함수로, 간단하게 front와 rear가 값이 같으면 공백 상태이다.

## 포화 상태 확인
```
int IsFull(CircularQueue* queue)
{
    // 같을 경우 포화 상태
    if(queue->front < queue->rear) {
        return (queue->rear - queue->front) == queue->capacity;
    }
    // 같을 경우 포화 상태
    else {
        return (queue->rear + 1) == queue->front;
    }
}
```
원형 큐가 포화 상태인지 확인하기 위해 두 가지의 경우의 수를 고려해야 한다.

<ul>
<li>전단이 후단 앞에 있을 때 후단과 전단의 차(rear - front)가 큐의 용량(capacity)과 동일하면 큐는 포화 상태임</li>
<li>전단이 후단과 같은 위치 또는 뒤에 있고 후단에 1을 더한 값(rear + 1)이 전단과 동일할 때 포화 상태임</li>
</ul>

## 원형 큐 사이즈 확인
```
int GetSize(CircularQueue* queue)
{
    // 후단이 전단보다 뒤에 있을 경우 그냥 빼서 리턴
    if(queue->front <= queue->rear) {
        return queue->rear - queue->front;
    }
    // 후단이 전단보다 앞에 있을 경우
    else {
        queue->rear + (queue->capacity - queue->front) + 1;
    }
}
```
if의 경우 전단이 후단보다 뒤에 있으니 그냥 - 연산만 하여 값을 리턴하면 되지만, else의 경우는 다르다.
<br>
후단이 현재 전단보다 앞에 있으므로, 전체 용량인 capacity에서 front 값을 빼고 rear 에 더하면 된다.


### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Queue/Circular%20Queue/CircularQueue.c)

### 실행 결과
```
Dequeue : 1 Front : 1 Rear : 4
Dequeue : 2 Front : 2 Rear : 4
Dequeue : 3 Front : 3 Rear : 4
Capacity : 10, Size : 2

Dequeue : 4 Front : 4 Rear : 2
Dequeue : 100 Front : 5 Rear : 2
Dequeue : 101 Front : 6 Rear : 2
Dequeue : 102 Front : 7 Rear : 2
Dequeue : 103 Front : 8 Rear : 2
Dequeue : 104 Front : 9 Rear : 2
Dequeue : 105 Front : 10 Rear : 2
Dequeue : 106 Front : 0 Rear : 2
Dequeue : 107 Front : 1 Rear : 2
Dequeue : 108 Front : 2 Rear : 2
```
