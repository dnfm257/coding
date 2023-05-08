#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string wb[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string bw[8] ={
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int N, M;

int wb_match(string s[], int n, int m){
    int cnt = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(s[i + n][j + m] != wb[i][j]){
                cnt++;
            }
        }
    }

    return cnt;
}

int bw_match(string s[], int n, int m){
    int cnt = 0;

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(s[i + n][j + m] != bw[i][j]){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    string s[N];

    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    int ans = 987654321;
    for(int i = 0; i < N - 7; i++){
        for(int j = 0; j < M - 7; j++){
            ans = min(ans, min(wb_match(s, i, j), bw_match(s, i, j)));
        }
    }

    cout << ans << "\n";
}