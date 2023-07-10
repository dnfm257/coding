#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

bool pos;

void BFS(int st, vector<int>& visited, vector<vector<int>> graph){
    queue<int> q;
    q.push(st);
    visited[st] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int nx = graph[now][i];
            
            // 방문한 적이 있는데 색깔이 같음 => NO 조건
            if(visited[nx] && visited[now] == visited[nx]){
                pos = false;
                return;
            }
            
            if(!visited[nx]) {
                q.push(nx);

                if(visited[now] == 1){
                    visited[nx] = 2;
                }
                else if(visited[now] == 2){
                    visited[nx] = 1;
                }
            }
        }
    }

    return;
}

string solution(vector<vector<int>> graph, int V){
    vector<int> visited(V + 1, 0); // -1, 1로 색깔구분
    
    // 비연결 그래프 시 다른 그래프도 BFS 실행
    for(int i = 1; i <= V; i++){
        if(visited[i] == 0){
            BFS(i, visited, graph);
        }

        if(!pos){
            break;
        }
    }

    if(pos){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int K, V, E;
    cin >> K;

    while(K--){
        pos = true;
        cin >> V >> E;
        vector<vector<int>> graph(V + 1);
        
        int a, b;
        for(int i = 0; i < E; i++){
            cin >> a >> b;
            graph[a].emplace_back(b);
            graph[b].emplace_back(a);
        }

        cout << solution(graph, V) << "\n";
    }
}