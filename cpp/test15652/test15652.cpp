#include <iostream>

using namespace std;

int N, M;
int arr[9];

void DFS(int tmp){
    if(tmp - 1 == M){
        for(int i = 1; i < tmp; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = 1; i <= N; i++){
        if(arr[tmp - 1] > i){
            continue;
        }
        arr[tmp] = i;

        DFS(tmp + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    DFS(1);
}