#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int N;
vector<string> field;
bool visited[25][25] = { false };
priority_queue<int, vector<int>, greater<int>> ans;

void BFS(pair<int, int> st){
    int cnt = 1;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    queue<pair<int, int>> q;
    q.push(st);
    visited[st.first][st.second] = true;

    while(!q.empty()){
        int now_X = q.front().first;
        int now_Y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx_X = now_X + dx[i];
            int nx_Y = now_Y + dy[i];

            if(nx_X < 0 || nx_X >= N || nx_Y < 0 || nx_Y >= N
             || visited[nx_X][nx_Y] || field[nx_X][nx_Y] == '0') continue;

            q.push(make_pair(nx_X, nx_Y));
            visited[nx_X][nx_Y] = true;
            cnt++;
        }
    }

    ans.push(cnt);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    string str;

    for (int i = 0; i < N; i++) {
        cin >> str;

        field.push_back(str);
    }
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if(!visited[i][j] && field[i][j] == '1'){
                BFS(make_pair(i, j));
            }
        }
    }

    cout << ans.size() << "\n";
    while(!ans.empty()){
        cout << ans.top() << "\n";
        ans.pop();
    }
}