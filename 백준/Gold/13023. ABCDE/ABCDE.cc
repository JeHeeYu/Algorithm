#include <iostream>
#include <vector>

using namespace std;

static vector<vector <int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int now, int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    /*
        A : 그래프 데이터 저장 인접 리스트
        visited : 방문 기록 저장 배열
        arrive : 도착 확인 변수
        N : 노드 개수
        M : 에지 개수
    */
    
    int N, M;
    
    // 도착하지 않은 상태로 초기화
    arrive = false;
    
    cin >> N >> M;
    
    A.resize(N);
    
    // 방문 배열 도착하지 않은 상태로 초기화
    visited = vector<bool>(N, false);
    
    for(int i = 0; i < M; i++) {
        int s, e;
        
        cin >> s >> e;
        
        A[s].push_back(e);
        A[e].push_back(s);
    }
    
    // 노드마다 DFS 실행
    for(int i = 0; i < N; i++) {
        DFS(i, 1);
        
        if(arrive) {
            break;
        }
    }
    
    if(arrive) {
        cout << 1 << "\n";
    }
    else {
        cout << 0 << "\n";
    }

    return 0;
}

void DFS(int now, int depth)
{
    // 깊이가 5거나 방문한 적이 있다면 프로그램 종료
    if(depth == 5 || arrive) {
        arrive = true;
        return;
    }
    
    visited[now] = true;
    
    for(int i : A[now]) {
        if(!visited[i]) {
            DFS(i, depth + 1); // 재귀 호출 시 depth를 1씩 증가하여 호출
        }
    }
    
    visited[now] = false;
}
