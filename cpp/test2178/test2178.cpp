#include <iostream>
#include <string>
#include <queue>

using namespace std;

int solution(int field[][101], int N, int M){
    int answer[101][101] = { 0 };
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    bool visited[101][101] = { false };

    queue<pair<int, int>> q;
    q.push({1, 1});
    answer[1][1] = 1;
    visited[1][1] = true;

    while(!q.empty()){
        int now_x = q.front().first;
        int now_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx_x = now_x + dx[i];
            int nx_y = now_y + dy[i];

            if(nx_x >= 1 && nx_x <= N && nx_y >= 1 && nx_y <= M
            && !visited[nx_x][nx_y] && field[nx_x][nx_y] == 1){
                q.push({nx_x, nx_y});
                visited[nx_x][nx_y] = true;
                answer[nx_x][nx_y] = answer[now_x][now_y] + 1;
            }
        }
    }

    return answer[N][M];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int field[101][101] = { 0 };
    
    cin >> N >> M;

    string s;
    for(int i = 1; i <= N; i++){
        cin >> s;

        for(int j = 1; j <= M; j++){
            field[i][j] = s[j - 1] - '0';
        }
    }

    cout << solution(field, N, M) << "\n";
}