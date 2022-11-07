# 스택(Stack)

### 요약
<ul>
    <li>데이터를 일시적으로 저장히기 위해 사용하는 자료구조로 한 곳에서만 입출력이 일어남</li>
    <li>먼저 들어간 데이터는 마지막에 나오는 FIFO 구조 (First In - Last Out)</li>
    <li>마지막에 들어간 데이터는 먼저 나오는 LIFO 구조 (Last In - First Out)</li>
    <li>데이터를 담는 행위를 Push, 데이터를 추출하는 행위를 Pop이라고 함</li>
    <li>중요 구조체 멤버로 저장할 메모리 공간, 현재 가리키는 위치, 최대 사이즈 3가지가 필요</li>
</ul>

## 스택(Stack)이란
스택은 바닥에서 부터 데이터를 쌓아 올리는 자료구조의 일종이며, 스택의 입/출력은 오로지 꼭대기에서만 이루어진다.
<br>
<b>가장 먼저 들어간 데이터는 가장 나중에 나오는 구조이고(FILO First In - Last Out),</b>
<b>가장 마지막에 들어간 데이터는 가장 먼저 나오는 구조이다(LIFO Last In - First Out),</b>
<br>
<br>
C언어에서 변수를 선언한 후 수명주기가 끝나면 변수를 자동 제거하는 메모리도 스택으로 구현되어 있다.
<br>
그래서 지역 변수는 스택에 할당된다고도 표현한다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200297750-403b7fe7-5162-4c5e-a298-c45029dc3d54.JPG" width="300" height="300">
<br>
<br>
스택의 가장 중요한 부분은 <b>요소의 삽입과 삭제가 한쪽 끝에서만 이루어지는 것</b>이다.
<br>
<br>
스택은 네트워크 프로토콜, 컴파일러의 분석기, 이미지 편집 프로그램의 되돌리기 등 중요한 자료구조이다.
<br>
<br>
스택의 핵심 기능은 요소는 삽입하는 Push와 제거하는 Pop 연산 기능이다.
<br>
아래 이미지 중 왼쪽 이미지는 스택 맨 위에 새로운 요소를 담고(Push), 오른쪽 이미지는 나중에 들어온 데이터가 나가는(Pop) 이미지이다.
<br>
<br>
<img src="https://user-images.githubusercontent.com/87363461/200298247-29985853-73f4-419b-a54b-99155fb20fcd.JPG" width="400" height="300">
<img src="https://user-images.githubusercontent.com/87363461/200298335-8fcb281f-46fd-4673-914f-110cb11ecab4.JPG" width="300" height="300">
<br>
<br>

## 스택의 구조체
스택의 구조체는 간단하게 배열을 이용해 구성할 수 있다.
<br>
배열을 이용할 경우 용량을 동적으로 변경할 때 비용이 크지만, 쉽게 구현할 수 있다는 장점이 있다.
<br>
<br>
배열 기반의 스택은 각 노드를 동적으로 생성하고, 제거하는 대신, 스택 생성 초기에 사용자가 부여한 용량을 한꺼번에 생성한다.
<br>
그리고 최상위 노드의 위치를 나타내는 변수를 두고 삽입과 제거 연산을 수행한다.
<br>
<br>
스택의 구조체는 크게 3가지의 데이터 구조가 필요하다.
<ul>
<li>용량</li>
<li>최상위 노드의 위치</li>
<li>저장할 메모리</li>
</ul>
<pre>
typedef struct _Stack
{
    int capacity;
    int top;
    int *buf;
} Stack;
</pre>
capacity : 스택의 최대 용량을 나타내는 변수
<br>
top : 스택에 쌓여 있는 데이터를 나타내며, 비어 있을 경우 0(buf[0]), 가득 차 있을 경우 capacity(buf[top - 1]의 값과 같다.
<br>
buf : 스택으로 푸시된 데이터를 저장할 용도의 배열을 가리키는 변수로, Create 함수로 메모리 공간 할당을 한다.

## 스택의 함수
<pre>
void Create(Stack* s, int capacity);        // 메모리 공간 초기화
int Push(Stack* s, int x);                 // 스택에 데이터 푸쉬
int Pop(Stack* s, int* x);                  // 스택에 데이터 팝
int Peek(const Stack* s, int* x);           // 스택 최상위 메모리 확인
void Clear(Stack* s);                       // 스택에 있는 모든 데이터 삭제
int Capacity(const Stack* s);               // 스택 용량 확인
int Size(const Stack* s);                   // 스택에 있는 데이터 수
int IsEmpty(const Stack* s);                // 스택이 비어 있는지 확인
int IsFull(const Stack* s);                 // 스택이 가득 찼는지 확인
int Search(const Stack* s, int x);          // 스택에서 데이터 검색
void Print(const Stack* s);                 // 스택 데이터 출력
void Terminate(Stack* s);                   // 스택 메모리 삭제
</pre>
