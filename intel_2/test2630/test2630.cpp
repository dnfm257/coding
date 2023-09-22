#include <iostream>

using namespace std;

int num_0 = 0;
int num_1 = 0;
int field[128][128];

void solution(int x, int y, int N){
    int temp = field[x][y];
    bool diff = false;
    for(int i = x; i < x + N; i++){
        for(int j = y; j < y + N; j++){
            if(temp != field[i][j]){
                diff = true;
                break;
            }  
        }
    }

    if(!diff && temp == 1)
        num_1++;
    else if(!diff && temp == 0)
        num_0++;
    else{
        solution(x, y, N/2);
        solution(x + N/2, y, N/2);
        solution(x, y + N/2, N/2);
        solution(x + N/2, y + N/2, N/2);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N = 0;
    cin >> N;

    int tmp = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> field[i][j];
        }
    }

    solution(0, 0, N);
    cout << num_0 << "\n" << num_1 << "\n";
}