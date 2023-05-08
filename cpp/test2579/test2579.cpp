/*
DP[N] = DP[N - 2] + Arr[N] or DP[N - 3] + Arr[N - 1] + Arr[N]
*/

#include <iostream>

using namespace std;

int N;
int st[302];
int dp[302];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> st[i];
    }

    dp[1] = st[1];
    dp[2] = st[2] + dp[1];
    for(int i = 3; i <= N; i++){
        dp[i] = max(dp[i - 2], dp[i - 3] + st[i - 1]) + st[i];
    }

    cout << dp[N] << "\n";
}