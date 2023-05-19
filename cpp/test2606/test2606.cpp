#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(int N, vector<vector<int>> graph){
    int answer = 0;
    vector<bool> virus(N + 1);

    stack<int> s;
    s.push(1);
    virus[1] = true;

    while(!s.empty()){
        int now = s.top();
        s.pop();

        for(int i = 0; i < graph[now].size(); i++){
            int nx = graph[now][i];

            if(!virus[nx]){
                s.push(nx);
                virus[nx] = true;
                answer++;
            }
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M = 0;
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }

    cout << solution(N, graph) << "\n";
}