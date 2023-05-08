#include <iostream>

using namespace std;

int lst[1001];
int dp[1001];
int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> lst[i];
    }

    dp[0] = 0;
    int ans = 0;
    for(int i = 1; i <= N; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(lst[i] > lst[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}