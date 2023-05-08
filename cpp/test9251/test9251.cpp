/*
  A C A Y K P
C 0 1 1 1 1 1
A 1 1 2 2 2 2
P 1 1 2 2 2 3
C 1 2 2 2 2 3
A 1 2 3 3 3 3
K 1 2 3 3 4 4

문자가 서로 같으면
현재위치 값 = 왼쪽 대각 + 1
문자가 서로 다르면
현재위치 값 = max(왼쪽 값, 위쪽 값)

LCS = 왼쪽 대각방향으로 큰 수가 처음 나온 곳
*/

#include <iostream>
#include <string>

using namespace std;
string s1, s2;
int dp[1002][1002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;

    for(int i = 0; i < s1.length(); i++){
        for(int j = 0; j < s2.length(); j++){
            if(s1[i] == s2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[s1.length()][s2.length()] << "\n";
}