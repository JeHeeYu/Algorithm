#include <iostream>
#include <vector>

using namespace std;

static vector<vector <int>> result;
static vector<bool> visited;
void DFS(int v);

int main()
{
    // ios::sync_wtih_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    
    /*
        result : 그래프 데이터 저장 인접 리스트
        visited : 방문 기록 저장 배열
    
        N : 정점의 개수
        M : 간선의 개수
        u : 양 끝점
        v : 양 끝점
        count : 요소의 개수
    */
    
    int N, M, u, v, count = 0;
    
    cin >> N >> M;
    
    result.resize(N + 1);
    visited = vector<bool>(N + 1, false);
    
    for(int i = 0; i < M; i++) {
        cin >> u >> v;
        
        // 인접 리스트 배열에 그래프 데이터 저장
        result[u].push_back(v);
        result[v].push_back(u);
    }
    
    for(int i = 1; i < N + 1; i++) {
        // 방문하지 않은 노드가 없을 때까지 반복
        if(!visited[i]) {
            count++;
            DFS(i);
        }
    }
    
    cout << count << "\n";

    return 0;
}

void DFS(int v)
{
    // 방문한 노드인 경우 return
    if(visited[v]) {
        return;
    }
    
    // 방문 처리
    visited[v] = true;
    
    for(int i : result[v]) {
        // 연결 노드 중 방문하지 않은 노드만 탐색
        if(visited[i] == false) {
            DFS(i);
        }
    }
}
