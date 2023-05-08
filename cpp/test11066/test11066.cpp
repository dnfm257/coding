#include <iostream>

#define MAX 987654321

using namespace std;

int T, K;
int sum[501];
int dp[501][501];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        cin >> K;

        for(int i = 1; i <= K; i++){
            int a;
            cin >> a;

            sum[i] = sum[i - 1] + a;
        }

        for(int i = 1; i <= K; i++){
            for(int j = 1; j <= K - i; j++){
                dp[j][j + i] = MAX;
                for(int k = j; k <= i + j; k++){
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k + 1][j + i] + sum[j + i] - sum[j - 1]);
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
}