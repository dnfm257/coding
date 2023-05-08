#include <iostream>

using namespace std;

int field[129][129];
int N, ans_whi, ans_bl;

void DFS(int st_x, int st_y, int n){
    bool whi = true;
    bool bl = true;

    for(int i = st_x; i < st_x + n; i++){
        for(int j = st_y; j < st_y + n; j++){
            if(field[i][j] == 1){
                whi = false;
            }
            else{
                bl = false;
            }
        }
    }

    if(whi){
        ans_whi++;
    }
    else if(bl){
        ans_bl++;
    }
    else{
        DFS(st_x, st_y, n/2);
        DFS((st_x + n/2), st_y, n/2);
        DFS(st_x, (st_y + n/2), n/2);
        DFS((st_x + n/2), (st_y + n/2), n/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> field[i][j];
        }
    }

    DFS(1, 1, N);

    cout << ans_whi << "\n";
    cout << ans_bl << "\n";
}