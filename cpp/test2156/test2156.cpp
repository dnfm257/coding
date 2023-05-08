#include <iostream>

using namespace std;

int N;
int dp[10001];
int podo[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> podo[i];
    }

    dp[1] = podo[1];
    dp[2] = podo[2] + dp[1];
    for(int i = 3; i <= N; i++){
        dp[i] = max(max(dp[i - 2], dp[i - 3] + podo[i - 1]) + podo[i], dp[i - 1]);
    }

    cout << dp[N] << "\n";
}