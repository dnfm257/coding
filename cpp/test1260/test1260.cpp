#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(int V, vector<vector<int>> lne, vector<bool>& visited){
    int now = V;
    visited[now] = true;
    cout << now << " ";

    for(int i = 0; i < lne[now].size(); i++){
        int nx = lne[now][i];

        if(!visited[nx]){
            DFS(nx, lne, visited);
        }
    }
}

void BFS(int V, vector<vector<int>> lne, vector<bool>& visited){
    queue<int> q;
    q.push(V);
    visited[V] = true;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        cout << now << " ";

        for(int i = 0; i < lne[now].size(); i++){
            int nx = lne[now][i];

            if(!visited[nx]){
                visited[nx] = true;
                q.push(nx);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;

    cin >> N >> M >> V;

    vector<vector<int>> lne(N + 1);
    vector<bool> visited(N + 1);

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        lne[a].push_back(b);
        lne[b].push_back(a);
    }

    for(int i = 1; i <= N; i++){
        sort(lne[i].begin(), lne[i].end());
    }
    
    DFS(V, lne, visited);
    cout << "\n";

    for(auto i : visited){
        cout << i << " ";
    }

    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    BFS(V, lne, visited);
    cout << "\n";

    for(auto i : visited){
        cout << i << " ";
    }
}