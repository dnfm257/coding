#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(int st, vector<vector<int>> field, vector<bool>& visited){
    stack<int> s;
    s.push(st);
    visited[st] = true;

    while(!s.empty()){
        int now = s.top();
        s.pop();

        for(int i = 0; i < field[now].size(); i++){
            int nx = field[now][i];

            if(!visited[nx]){
                s.push(nx);
                visited[nx] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers){
    int answer = 0;
    vector<vector<int>> field(n);

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(computers[i][j] == 1){
                field[i].emplace_back(j);
                field[j].emplace_back(i);
            }
        }
    }

    vector<bool> visited(n);

    while(find(visited.begin(), visited.end(), false) != visited.end()){
        auto it = find(visited.begin(), visited.end(), false);
        DFS(it - visited.begin(), field, visited);
        answer++;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> computers(N);
    int a, b;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a;
            computers[i].emplace_back(a);
        }
    }

    cout << solution(N, computers);
}