#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int N, int M, vector<int> memory, vector<int> cost){
    int answer = 0;
    int sz = 100 * N + 1;

    int dp[sz][N + 1];
    fill(&dp[0][0], &dp[sz - 1][N + 1], 0);

    for(int i = 1; i <= sz; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i][j - 1];

            if(i - cost[j] >= 0){
                dp[i][j] = max(dp[i][j], dp[i - cost[j]][j - 1] + memory[j]);
            }
        }

        if(dp[i][memory.size() - 1] >= M){
            answer = i;
            break;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    vector<int> memory;
    vector<int> cost;

    cin >> N >> M; // 앱 개수, 확보해야할 메모리용량

    memory.push_back(0);
    cost.push_back(0);
    for(int i = 0; i < N; i++){
        int a;
        cin >> a;
        memory.push_back(a);
    }
    for(int i = 0; i < N; i++){
        int b;
        cin >> b;
        cost.push_back(b);
    }

    cout << solution(N, M, memory, cost) << "\n";
}