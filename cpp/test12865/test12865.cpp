#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<pair<int, int>> itm;
int dp[101][100001];

int main(){
    cin >> N >> K;

    itm.push_back({0, 0});
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        itm.push_back({a, b});
    }

    for(int i = 1; i <= N; i++){
        for(int w = 1; w <= K; w++){
            if(w - itm[i].first >= 0){
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - itm[i].first] + itm[i].second);
            }
            else{
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << dp[N][K] << "\n";
}