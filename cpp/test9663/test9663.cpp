#include <iostream>

using namespace std;

int N, cnt;
int visited[16];
int location[16];

bool diagonal(int nxt){ // 대각선 검사
    for(int i = 0; i < nxt; i++){
        if(abs(location[nxt] - location[i]) == abs(nxt - i)){ // 두 점을 지나는 직선의 기울기가 1일때 = 대각선 위치
            return true;
        }
    }

    return false;
}

void DFS(int x){
    if(x == N){ // 경우의 수 + 1
        cnt++;
        return;
    }

    for(int y = 0; y < N; y++){
        location[x] = y;

        if(!visited[y] && !diagonal(x)){ // y값이 겹치지 않고 대각선 위치가 아닐 때
            visited[y] = true;
            DFS(x + 1);
            visited[y] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(0);

    cout << cnt << "\n";
}