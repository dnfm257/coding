/*
  -> dp[N /2] + 1
N -> dp[N /3] + 1
  -> dp[N -1] + 1
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp.push_back(0);
    dp.push_back(0);
    dp.push_back(1);
    dp.push_back(1);
    for(int i = 4; i <= N; i++){
        dp.push_back(dp[i - 1] + 1);

        if(i % 2 == 0){
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
        if(i % 3 == 0){
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[N] << "\n";
}