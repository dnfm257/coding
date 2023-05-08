#include <iostream>
#include <string>
#include <climits>

#define INF INT_MAX / 3

using namespace std;

int cnt[2500];
bool dp[2500][2500]; // A~B까지 펠린드롬이 맞는지 확인
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s;

    // 길이 1
    for(int i = 0; i < s.size(); i++){
        dp[i][i] = true;
    }

    // 길이 2
    for(int i = 0; i < s.size() - 1; i++){
        if(s[i] == s[i + 1]){
            dp[i][i + 1] = true;
        }
    }

    // 길이 3이상 => 같은 간격으로 검사, 간격을 1씩 증가
    for(int i = 1; i < s.size(); i++){ // 간격
        for(int j = 0; j < s.size() - i; j++){
            if(s[j] == s[j + i] && dp[j + 1][j + i - 1]){
                dp[j][j + i] = true;
            }
        }
    }

    cnt[0] = 0;
    for(int i = 1; i <= s.size(); i++){
        cnt[i] = INF;

        for(int j = 1; j <= i; j++){
            if(dp[j - 1][i - 1]){ // j ~ i까지가 펠린드롬이면
                cnt[i] = min(cnt[i], cnt[j - 1] + 1); // i까지의 갯수 & j전(j ~ i 범위 전) + 1까지의 개수 비교
            }
        }
    }

    cout << cnt[s.size()] << "\n";
}