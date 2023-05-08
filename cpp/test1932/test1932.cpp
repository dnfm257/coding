#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i < N; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                arr[i][j] += arr[i - 1][j];
            }
            else if(j == i){
                arr[i][j] += arr[i - 1][j - 1];
            }
            else{
                arr[i][j] += max(arr[i - 1][j - 1], arr[i - 1][j]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        ans = max(ans, arr[N - 1][i]);
    }

    cout << ans << "\n";
}