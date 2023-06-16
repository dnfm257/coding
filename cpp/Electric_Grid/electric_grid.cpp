#include <iostream>
#include <vector>

using namespace std;

int DFS(int st, vector<vector<int>> graph, vector<bool>& visited){
    int cnt = 1;
    if(graph[st].size() == 1){
        return 1;
    }

    for(int i = 0; i < graph[st].size(); i++){
        int nx = graph[st][i];
        
        if(!visited[nx]){
            visited[nx] = true;
            cnt += DFS(nx, graph, visited);
            visited[nx] = false;
        }
    }

    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 101;
    vector<vector<int>> graph(n + 1);
    for(auto& i : wires){
        graph[i[0]].emplace_back(i[1]);
        graph[i[1]].emplace_back(i[0]);
    }
    
    vector<bool> visited(n + 1, false);

    for(int i = 0; i < n - 1; i++){
        fill(visited.begin(), visited.end(), false);
        visited[wires[i][0]] = true;
        visited[wires[i][1]] = true;
        answer = min(answer, abs(DFS(wires[i][0], graph, visited) - DFS(wires[i][1], graph, visited)));
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> wires(n - 1);
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        wires[i].emplace_back(a);
        wires[i].emplace_back(b);
    }

    cout << solution(n, wires) << "\n";
}