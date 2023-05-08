#include <iostream>

using namespace std;

int arr[9];
int N, M;

void DFS(int tmp){
    if(tmp == M){ // 목표 길이 달성하면 출력
        for(int i = 0; i < M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= N; i++){
        arr[tmp] = i;
        DFS(tmp + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    DFS(0);
}