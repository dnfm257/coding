#include <iostream>

using namespace std;

int pht[65][65];
int N;

void DFS(int st_x, int st_y, int n){
    bool zero = true;
    bool one = true;
    for(int i = st_x; i < st_x + n; i++){
        for(int j = st_y; j < st_y + n; j++){
            if(pht[i][j] == 1){
                zero = false;
            }
            else{
                one = false;
            }
        }
    }

    if(zero){
        cout << "0";
    }
    else if(one){
        cout << "1";
    }
    else{
        cout << "(";
        DFS(st_x, st_y, n/2);
        DFS((st_x + n/2), st_y, n/2);
        DFS(st_x, (st_y + n/2), n/2);
        DFS((st_x + n/2), (st_y + n/2), n/2);
        cout << ")";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    char c;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> c;
            pht[j][i] = c - '0';
        }
    }

    DFS(1, 1, N);
}