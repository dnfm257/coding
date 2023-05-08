#include <iostream>

using namespace std;

int M ,N;
int field[501][501];
int dp[501][501];
bool visited[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int DFS(int y, int x){
    if(x == N && y == M){
        return 1; // 종점 = 1 >> 다시 되돌아가면서 1을 더한다(top-down)
    }

    if(visited[y][x]){
        return dp[y][x];
    }

    visited[y][x] = true;
    for(int i = 0; i < 4; i++){
        int nt_x = x + dx[i];
        int nt_y = y + dy[i];

        if(field[nt_y][nt_x] < field[y][x] 
        && nt_x > 0 && nt_y > 0 && nt_x <= N && nt_y <= M){
            dp[y][x] += DFS(nt_y, nt_x);
        }
    }

    return dp[y][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;

    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            cin >> field[i][j];
        }
    }

    cout << DFS(1, 1) << "\n";
}