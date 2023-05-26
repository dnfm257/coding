#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS 효율성 실패(시간초과)
/*bool visited[101][101];
int answer = 100000;

void DFS(vector<vector<int>> map, int step, pair<int, int> st){
    int now_x = st.first;
    int now_y = st.second;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    if(now_x == map.size() - 1 && now_y == map[0].size() - 1){
        answer = min(step, answer);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nx_x = now_x + dx[i];
        int nx_y = now_y + dy[i];

        if(nx_x >= 0 && nx_x < map.size() && nx_y >= 0 && nx_y < map[0].size()){
            if(!visited[nx_x][nx_y] && map[nx_x][nx_y] != 0){
                visited[nx_x][nx_y] = true;
                DFS(map, step + 1, {nx_x, nx_y});
                visited[nx_x][nx_y] = false;
            }
        }
    }
}

int solution(vector<vector<int>> map){
    DFS(map, 1, {0, 0});

    if(answer >= 100000){
        return -1;
    }
    return answer;
}*/

int solution(vector<vector<int>> maps){
    int answer = -1;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int n = maps.size();
    int m = maps[0].size();
    int visited[n][m];
    fill(&visited[0][0], &visited[n - 1][m], 0);
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        if(now_x == n - 1 && now_y == m - 1){
            answer = visited[now_x][now_y];
            break;
        }

        for(int i = 0; i < 4; i++){
            int nx_x = now_x + dx[i];
            int nx_y = now_y + dy[i];

            if(nx_x >= 0 && nx_x < n && nx_y >= 0 && nx_y < m){
                if(visited[nx_x][nx_y] == 0 && maps[nx_x][nx_y] == 1){
                    visited[nx_x][nx_y] = visited[now_x][now_y] + 1;
                    q.push({nx_x, nx_y});
                }
            }
        }
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int a;
    vector<vector<int>> map(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> a;
            map[i].emplace_back(a);
        }
    }

    cout << solution(map) << "\n";
}