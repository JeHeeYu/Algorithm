## DFS(Depth First Search)와 BFS(Breadth First Search)

DFS와 BFS는 그래프 탐색 기법(그래프의 각 정점을 순회하는 기법)으로 가장 대표적인 알고리즘으로 알려져있는 알고리즘 방식이다.
<br>
<br>
단어 그대로 DFS는 깊이 우선 탐색, BFS는 너비 우선 탐색을 말한다.
<br>
깊이 우선 탐색(DFS)은 그래프 정렬 알고리즘의 기반이 되고, 너비 우선 탐색(BFS)은 그래프에서 최단 경로를 찾는 알고리즘이다.


## 깊이 우선 탐색(DFS, Depth First Search)
깊이 우선 탐색은 더 나아갈 길이 보이지 않을 때까지 깊이 들어간다라는 원칙으로 그래프 내의 정점을 방문하는 알고리즘이다.
<br>
이 알고리즘은 길이 나오지 않을 때까지 그래프의 정점을 타고 깊이 들어가다가, 더 이상 방문해왔던 정점 말고는 다른 이웃을 갖고 있지 않은 정점을 만나면 뒤로 돌아와 다른 경로로 뻗어 있는 정점을 타고 방문을 재개하는 방식으로 동작한다,
<br>
<br>
말이 복잡한데, 이 내용을 단계 별로 설명하면 아래와 같다.

<ol>
  <li>시작 정점을 밟은 이후 정점을 '방문'으로 표시</li>
  <li>이 정점과 이웃 정점(인접) 중 아직 방문하지 않은 곳을 선택하여 이를 시작 정점으로 삼고, 다시 깊이 우선 탐색 시작(즉, 1번 단계 다시 수행)</li>
  <li>더 이상 방문하지 않은 이웃 정점이 없으면 이전 정점으로 돌아가 2번 단계 수행</li>
  <li>이전 정점으로 돌아가도 더 이상 방문할 이웃 정점이 없으면 그래프의 모든 정점을 방문했다는 뜻으로 탐색 종료</li>
</ol>

아래 그래프 예시는 깊이 우선 탐색을 하는 과정으로 '방문'은 보라색으로 표시한다.
<br>
먼저 가장 처음 정점인 시작 정점을 밟고 '방문'으로 표시한다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208348440-11567965-2f2d-4951-9910-f6dceaa590b8.png)

<br>

그리고 인접 정점 중 하나를 선택해 그 곳으로 이동한다.
<br>
정점 1의 인접 정점은 2와 3이 있는데, 먼저 방문 여부는 상관 없으며, 여기서는 정점 2를 먼저 방문한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/208348815-29f72f2e-7052-4cb3-a212-637d2018544f.png)

<br>

정점 2에도 인접 정점이 2개 있는데, 4와 5중 먼저 정점 4를 방문하고 '방문'으로 표시한다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208348919-7750a336-6479-4486-b179-0327b9bb289e.png)

<br>

정점 4에서도 인접 정점에 대해 같은 원리로 방문하는데, 인접 정점 5와 7중 5를 방문하고, 다시 7을 방문한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/208349032-1e33bbe7-306c-462f-9229-323016f20b09.png)

<br>

정점 7의 경우 더 이상 방문할 인접 정점이 없으므로, 다시 이전 정점으로 되돌아가야 한다.
<br>
이전 정점인 5로 되돌아가 방문하지 않은 정점을 찾는데, 방문하지 않은 정점은 없는 것으로 확인된다.
<br>
<br>
다시 이전 정점인 정점 4로 돌아가서 방문하지 않은 정점을 확인하는데도 없으므로 다시 이전 정점인 2로 되돌아간다.
<br>
2도 없으므로 다시 1로 되돌아가고, 정점 1에는 방문하지 않은 정점 3이 있으므로 이 정점을 방문한다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208349511-066491d7-2d13-4d26-8b0d-9964bd8d197b.png)

<br>

정점 3의 인접 정점에는 4와 6이 있지만, 4는 이미 방문한 정점이므로 정점 6을 방문한다.
<br>
정점 6 방문 후 다시 뒤로 돌아가 방문할 곳을 찾아야 하지만, 모든 정점을 방문하였으므로 새로 방문할 곳이 없어 탐색을 종료한다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208349587-709f6d8e-f710-4e8c-9f38-edb4f0959832.png)

<br>

이 과정이 깊이 우선 탐색(DFS)의 과정이며, 코드로 나타내면 아래 코드와 같다.
```
void DFS(Vertex* v)
{
    Edge* e = NULL;
    
    printf("%d ", v->data);
    
    // '방문' 표시
    v->visited = Visited;
    
    e = v->adjacencyList;
    
    // 현재 정점의 모든 인접 정점에 대해 재귀 호출
    while(e != NULL) {
        // 방문하지 않은 정점의 경우 탐색
        if(e->target != NULL && e->target->visited == NotVisited) {
            DFS(e->target);
        }
        
        e = e->next;
    }
}
```


## 너비 우선 탐색(Breadth First Search)
너비 우선 탐색에서는 시작 정점을 지난 후 깊이가 1인 모든 정점을 방문하고, 그 다음 깊이가 2인 모든 정점을 방문한다.
<br>
이렇게 한 단계씩 깊이를 더해가며 해당 깊이에 있는 모든 정점을 방문하다가 더 이상 방문할 정점이 없을 때 탐색을 종료한다.
<br>
<br>
아래 그래프는 너비 우선 탐색을 진행할 그래프이다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208350047-2483cdaf-92b5-4aef-a5ad-5f48c9a43e64.png)

<br>

먼저 깊이 0에 있는 정점은 1밖에 없으므로 1을 제일 먼저 방문한다.
<br>
깊이 1에 있는 정점은 각각 2와 3 정점이므로 이 두 정점을 방문한다.
<br>
<br>
다시 깊이 2 정점들(4, 5, 6), 깊이 3정점(4)을 방문하고, 그 다음 깊이 4 정점은 없으므로 탐색을 종료한다.
<br>
<br>
따라서 너비 우선 탐색을 동작하기 위해 다른 자료구조나 재귀 호출을 이용할 수 있지만, 여기서는 큐를 이용하여 너비 우선 탐색을 수행하낟.
<br>
이 과정들을 나열하면 다음과 같다.

<ol>
  <li>시작 정점을 '방문'으로 삽입하고 큐에 삽입</li>
  <li>큐에서 정점을 제거하고 제거한 정점의 인접 정점 중에서 아직 방문하지 않은 곳을 '방문'으로 표시하고 큐에 삽입</li>
  <li>큐가 비면 탐색이 종료된 것으로 큐가 비기 전까지 2 과정 반복 수행</li>
</ol>

이 과정을 그래프로 표시하면 다음 과정과 같다.
<br>
<br>
먼저 시작 정점을 '방문'으로 표시하고 큐에 삽입한다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208350475-d7c897c5-2697-4832-94f3-f0501084b7e6.png)

<br>

이제 3단계(큐가 비었을 때) 조건을 만족할 때까지 2단계 과정을 반복해서 수행하면 된다.
<br>
큐에 정점 1이 있는데, 이 정점을 제거하고 방문하지 않은 곳을 확인하니 정점 2와 3이 있다.
<br>
<br>
이 정점들을 방문하고, 다시 큐에 삽입한다.
<br>

![image](https://user-images.githubusercontent.com/87363461/208352108-3034bb25-488b-4ff8-9cbe-ae16daf2912b.png)

<br>

다시 큐를 확인하는데, 큐에는 정점 2와 정점 3이 들어 있는데 큐의 전단에 있는 정점을 제거하고 인접 정점을 조사한다.
<br>
전단 정점인 정점 2를 제거하고, 2의 인접 정점인 정점 4와 정점 5를 방문하고 큐에 삽입한다.
<br>
<br>
이렇게 하면 큐에는 정점 3, 4, 5 가 삽입되어 있다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208352265-47b3a5c1-9c0a-438a-bc73-12efeeb7eebc.png)

<br>

다시 큐의 전단인 정점 3을 큐에서 제거하고, 인접 정점들을 조사한다.
<br>
인접 정점 중 정점 4는 이미 방문했으므로 방문하지 않은 정점 6을 방문하고 큐에 삽입한다.
<br>
<br>
큐에는 이제 정점 4, 5, 6이 삽입되어 있다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208352355-a69baf57-7e8e-435a-9545-cd37f6d1fa13.png)

<br>

다시 큐의 전단 정점 4를 큐에서 제거하고, 인접 정점들을 조사한다.
<br>
인접 정점 중 정점 5는 이미 방문했으므로 방문하지 않은 정점 7을 큐에 삽입한다.
<br>
<br>
큐에는 이제 정점 5, 6, 7이 삽입되어 있다.

<br>

![image](https://user-images.githubusercontent.com/87363461/208352475-2f6ff5b7-0a34-48b0-b54f-28043d52981c.png)

<br>

큐에는 이제 정점 5, 6, 7이 들어 있는데, 정점 5를 제거, 6을 제거, 7을 제거하더라도 방문하지 않은 인접 정점은 없다.
<br>
이제 큐에 남은 정점이 없으므로 탐색을 종료한다.
<br>
<br>
이 과정을 코드로 구현하면 아래 코드와 같다.
```
void BFS(Vertex* v, LinkedQueue* queue)
{
    Edge* e = NULL;
    
    printf("%d ", v->data);
    v->visited = Visited;
    
    // 시작 정점을 큐에 삽입
    Enqueue(queue, CreateNode(v));
    
    // 큐가 비지 않았을 경우
    while(!IsEmpty(queue)) {
        // 큐에서 전단 제거
        Node* temp = Dequeue(queue);
        v = temp->data;
        e = v->adjacencyList;
        
        // 큐에서 꺼낸 정점의 인접 정점 조사
        while(e != NULL) {
            v = e->target;
            
            // 방문하지 않은 접점들 방문
            if(v != NULL && v->visited == NotVisited) {
                printf("%d ", v->data);
                v->visited = Visited;
                Enqueue(queue, CreateNode(v));
            }
            
            e = e->next;
        }
    }
}
```

### [예제 코드](https://github.com/JeHeeYu/Algorithm/blob/main/Graph/DFS%20BFS/DFS_BFS)
예제 코드로, 링크드 큐를 이용해서 구현한 예제이다.

### 실행 결과
```
Enter Mode : (0 : DFS, 1 : BFS) 0
1 2 4 5 7 3 6 
Enter Mode : (0 : DFS, 1 : BFS) 1
1 2 3 4 5 6 7 
```
