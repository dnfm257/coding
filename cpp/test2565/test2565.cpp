#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dp[102];
vector<pair<int, int>> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    arr.push_back({0, 0});
    for(int i = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());
    
    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i].second > arr[j].second){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << N - ans << "\n";
}