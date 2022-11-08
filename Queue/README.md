# 큐(Queue) 정리 내용

### 요약
링 버퍼 큐 복잡도 : O(1)
<br>
배열 큐 복잡도 : O(n)
<br>
<ul>
<li>가장 먼저 넣은 데이터를 가장 먼저 꺼내는 선입선출 구조인 FIFO(First In - First Out) 구조를 따름</li>
<li>큐에 데이터를 넣는 작업을 인큐(Enqueue), 또는 스택과 같이 푸쉬(Push)라고 함</li>
<li>큐에서 데이터를 꺼내는 작업을 디큐(Dequeue) 또는 스택과 같이 팝(Pop)이라고 함</li>
<li>데이터를 꺼내는 쪽을 프론트(Front), 데이터를 넣는 쪽을 리어(Rear)라고 함</li>
<li>링 버퍼는 배열의 처음과 끝이 연결되어 있는 구조로, 배열 요소를 앞쪽으로 옮기지 않아도 되어 좀 더 효율적인 구조로 사용 가능</li>
<li>일반 배열로 사용하는 큐로 구현 시 배열 요소를 앞쪽으로 옮겨야 하는 작업이 필요</li>
</ul>

## 큐(Queue)란
큐란 스택과 비슷한 자료구조로, 데이터를 일시적으로 쌓아 놓고 사용하는 자료구조의 일종이다.
<br>
큐는 가장 먼저 넣은 데이터를 가장 먼저 꺼내는 선입선출 구조인 FIFO(First In - First Out) 구조를 따른다.
<br>
<br>
예를 들어, 은행 창구에서 차례를 기다리는 대기열이나 마트에서 계산을 기다리는 대기열을 들 수 있다.
<br>
<br>
큐에 데이터를 넣는 작업을 인큐(Enqueue), 또는 스택과 같이 푸쉬(Push)라 하고,
<br>
큐에서 데이터를 꺼내는 작업을 디큐(Dequeue) 또는 스택과 같이 팝(Pop)이라고 표현한다.
<br>
<br>
그리고 데이터를 꺼내는 쪽을 프론트(Front), 데이터를 넣는 쪽을 리어(Rear)라고 한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200543544-572cc6a7-75b7-4b96-a7dd-c74f5148d2ab.JPG" width="500" height="200">
<br>
<br>
이 글에서는 일반 배열만 사용해서 만드는 큐가 아닌, 링 버퍼 큐에 관한 예제이다.
<br>
링 버퍼는 배열의 처음과 끝이 연결되어 있는 구조로, 배열 요소를 앞쪽으로 옮기지 않아도 되어 좀 더 효율적인 구조로 사용할 수 있다.
<br>
링 버퍼 큐에서는 프론트가 맨 처음 요소의 인덱스를 가리키고, 리어가 맨 끝 요소의 하나 뒤의 인덱스를 가리킨다. (저장할 위치 미리 선정)
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200544936-59f6ea00-6ef5-4c93-b6a8-9f86afc91e41.JPG" width="450" height="200">

## 인큐와 디큐 과정
인큐와 디큐를 거치면 포론트와 리어가 아래와 같은 과정을 거치게 된다.
<ol>
  <li>7개의 데이터(35, 56, 24, 68, 95, 73, 19)가 차례데로 que[7], que[8] ... que[11], que[0], que[1]에 저장된다.
  <br>
    여기서 프론트 값은 7, 리어 값은 2이다.</li>
  <li>82를 인큐하고, que[2]에 82를 저장한 다음, 리어 값을 1 증가시킨다.</li>
  <li>35를 디큐하고, 프론트 요소의 값 35를 빼고 프론트 값을 1 증가시킨다.</li>
</ol>
<img src="https://user-images.githubusercontent.com/87363461/200546292-3eda8170-1256-44c2-af1d-fbef666b240e.JPG" width="500" height="700">

## 큐의 구조체
일반 배열로 구성한 큐의 경우 3가지의 정보만 있으면 되지만, 링 버퍼 큐에서는 5가지의 필수 정보가 필요하다.
<ul>
<li>큐 최대 용량</li>
<li>큐 현재 요소 개수</li>
<li>프론트</li>
<li>리어</li>
<li>큐의 맨 앞 요소에 대한 위치</li>
</ul>
<pre>
typedef struct {
    int max;        // 큐의 최대 용량
    int num;        // 현재 요소 개수
    int front;      // 프론트, 데이터를 꺼내는 방향
    int rear;       // 리어, 데이터를 넣는 방향
    int *que;       // 큐의 맨 앞 요소에 대한 위치
} Queue;
</pre>

## 큐에서 사용하는 함수
<pre>
int Create(Queue *q, int max);          // 큐 메모리 생성
int Enque(Queue *q, int x);             // 큐에 데이터 인큐
int Deque(Queue *q, int *x);            // 큐에서 데이터 디큐
int Peek(const Queue *q, int *x);       // 맨 앞 데이터 확인
void Clear(Queue *q);                   // 모든 데이터 삭제
int Capacity(const Queue *q);           // 큐 최대 용량 확인
int Size(const Queue *q);               // 큐에 저장된 데이터 개수
int IsEmpty(const Queue *q);            // 큐가 비어 있는지 확인
int IsFull(const Queue *q);             // 큐가 가득 찼는지 확인
int Search(const Queue *q, int x);      // 큐에서 데이터 검색
void Print(const Queue *q);             // 큐 데이터 출력
void Terminate(Queue *q);               // 큐 메모리 소멸
</pre>
