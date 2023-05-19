# 프림 알고리즘(Prim`s Algorithm)

프림 알고리즘이란 로버트 프림(Robert C. prim)이 고안한 그래프에서 최소 신장 트리를 만들어 내는 알고리즘을 말한다.
프림 알고리즘은 최소 신장 트리에서 일반적으로 사용되는 두 가지 기법 중 하나이다.
<br>

## 프림 알고리즘을 이용한 최소 신장 트리 구현 과정

프림 알고리즘은 총 4가지 과정을 거치는데, 다음과 같은 과정을 거친다.
1. 그래프와 최소 신장 트리를 준비한다. (이때 최소 신장 트리는 노드가 하나도 없는 상태)
2. 그래프에서 임의의 정점을 시작 정점으로 선태갛여 최소 신장 트리의 뿌리 노드로 삽입
3. 최소 신장 트리에 삽입된 정점들과 이 정점들의 모든 인접 정점 사이에 있는 간선의 가종치 조사 후 간선 중 가장 가중치가 작은 것을 골라 이 간선에 연결된 인접 정점을 최소 신장 트리에 삽입 (새로 삽입되는 정점은 최소 신장 트리에 삽입된 기존 노드와 사이클을 형성해선 안됨)
4. 3번의 과정을 반복하다가 최소 신장 트리가 그래프의 모든 정점을 연결하게 되면 알고리즘 종료


이제 아래 예제는 위 4가지의 과정을 거쳐 그래프를 최소 신장 트리로 만들어내는 과정이다.
<br>
<br>

가장 먼저 아래와 같은 그래프가 존재한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222043638-9991d5d1-1f77-479f-87c8-e5989b4f8b1a.png)


<br>

우선 그래프에서 <b>시작 정점을 정해야</b> 한다. 
<br>
시작 정점은 어느 것을 골라도 상관 없으며, 고른 정점은 시작 정점이면서 동시에 최소 신장 트리의 뿌리 노드가 된다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222044483-e19a8f74-0ee0-4f45-b662-8da1a6e5d7a2.png)



<br>

정점 B에 연결된 간선들을 살펴보면 B-A, B-C, B-F 총 3개가 존재하는 것을 볼 수 있다.
> 가중치의 오름차순 표시
<br>
이 중에서 먼저 가장 가중치가 작은 간선은 B-A(35)이므로 A를 최소 신장 트리에 추가한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222044001-24ff69e9-78e8-4252-925f-b444b34d99b3.png)


<br>

이제 최소 신장 트리에 존재하는 노드는 B와 A로 2개이며, 다시 이들 노드에 연결된 간선들을 찾는다.
<br>
이들 노드에 연결된 간선들은 B-C(126), B-F(150), A-E(247) 로 총 3개이며, 다시 <b>최소 가중치</b>를 가진 간선을 찾는다.
<br>
<br>
최소 가중치는 B-C 간선이므로, C를 최소 신장 트리에 추가한다.
<br>
C가 추가 되면서 최소 신장 트리의 노드는 모두 3개가 되었으며, 다시 조사해야 할 간선도 4개가 된다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222044403-7970cd72-91c5-46a1-a0cd-cda779654df7.png)


<br>

이번에 조사해야 할 간선은 C-D(117), B-F(150), C-G(220), A-E(247)로 최소 가중치 간선은 C-D(117)으로 D를 최소 신장 트리에 추가한다.
> C-F 간선은 빠졌는데, C-F 간선이 B-C-F를 통과하는 사이클을 형성하기 때문이다. B-F, C-F 둘 중 하나를 제외하면 되는데, C-F의 가중치가 B-F보다 더 커서 C-F를 제외함

<br>

![image](https://user-images.githubusercontent.com/87363461/222044802-5cdfec23-7ec8-495a-a36a-d291bd359232.png)

<br>

다시 과정을 반복하면서 최소 가중치를 찾아 조사해야 한다.
<br>
조사할 간선은 3개로, B-F(150), C-G(220), A-E(247) 중 B-F(150) 이므로 F를 최소 신장 트리에 추가한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222044920-0cb2fe8b-2d05-46bf-b180-88259d32531b.png)


<br>

F가 최소 신장 트리에 추가됨으로써 조사 대상 간선에 큰 변화가 생기게 된다.
<br>
<br>
A-E 간선은 가중치가 더 작은 F-E 간선에 의해, 또 C-G 간선 역시 가중치가 더 작은 F-G 간선에 의해 조사 대상에서 제거되었다.
<br>
그리고 F-H 간선이 조사 대상으로 새로 추가된다.
<br>
<br>
다시 새로운 간선을 찾는데, F-E(82), F-H(120), F-G(154) 중 최소 가중치 간선은 F-E(82)이므로 E를 최소 신장 트리에 추가한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222045144-188bacd7-a8f2-480b-8cb3-6006d75c166b.png)


<br>

F-H 간선은 사이클 형성 이슈로 인해 조사 대상에서 제거되고, 이후 조사할 간선은 E-H(98)와 F-G(154) 2개이다.
<br>
더 작은 가중치 값은 E-H(98) 간선으로 최소 신장 트리에 H를 추가한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222045237-ce3af1ee-3c6f-4d9d-927e-ecd5625fa30f.png)


<br>

조사 대상 간선이 F-G(154) 간선 하나만 남았으므로 G를 최소 신장 트리에 추가한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222045335-e8b95b2d-638d-45ee-a9c1-03407223cc41.png)


<br>

이제 마지막으로 조사 대상 간선이 G-I(106) 하나만 남았으므로 정점 I를 최소 신장 트리에 추가한다.
<br>
이것으로 최소 신장 트리 구축이 완성되었다.
<br>

![image](https://user-images.githubusercontent.com/87363461/222045438-7e0d86a1-175d-4731-8b1f-e11b3eb64499.png)


<br>

## 프림 알고리즘의 고려해야 할 문제점
프림 알고리즘의 구현은 간단해 보일 수 있지만, 2가지의 문제를 고려해야 한다.

### 첫 번째로 어떤 자료구조를 최소 신장 트리에 사용할 것인가?
보통 배열, 링크드 리스트, 트리, 그래프 등을 사용할 수 있다.

### 두 번째로 최소 가중치를 골라내는 과정에서 발생하는 성능 문제
조사 대상 간선 중 최소 가중치를 골라내는 작업의 성능 문제가 심각한 문제이다.
<br>
최소 신장 트리에 정점이 하나 추가될 때마다 그 수가 늘어나거나 줄어드는 조사 대상 간선 집합 속에서 찾는 것 때문이다.
<br>
<br>
정점이 새로 추가될 때마다 모든 그래프의 정점을 순회하고, 이 정점들이 최소 신장 트리에 추가되었는지 확인해야 한다.
<br>
또한 최소 신장 트리에 추가된 모든 정점의 간선을 조사해서 최소 가중치를 찾아야 한다.
<br>
<br>
만약 그래프에 정점이 N개 존재한다고 할 경우 정점 추가 작업을 N회, 정점 추가 시 그래프 내 정점 N개를 순회해야 한다.
<br>
즉, N * N회(N^2)의 반복을 처리해야 한다.