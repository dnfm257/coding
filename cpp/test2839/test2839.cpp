#include <iostream>

using namespace std;

int N;

int bong(int a, int b){
    if(a * 5 + b * 3 == N){
        return a + b;
    }
    
    return 987654321;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    int ans = 987654321;
    for(int i = 0; i <= N/5; i++){
        for(int j = 0; j <= N/3; j++){
            ans = min(ans, bong(i, j));
        }
    }

    if(ans == 987654321){
        cout << "-1" << "\n";
    }
    else{
        cout << ans << "\n";
    }
}