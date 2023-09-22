#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int>& a, 
const pair<string, int>& b){
    if(a.second == b.second){ // 자주나오는 단어
        if(a.first.size() == b.first.size()){ // 긴 단어
            return a < b; // 사전순
        }

        return a.first.size() > b.first.size();
    }
    return a.second > b.second;
}

void solution(string* s, int M, int Size){
    unordered_map<string, int> res;

    for (int i = 0; i < Size; i++) {
        string tmp = s[i];
        if(res.find(tmp) != res.end()){ // 이미 있으면
            res[tmp]++;
            continue;
        }
        if(tmp.size() < M) continue; // 사이즈 이하는 탈락
        res.insert(make_pair(s[i], 0));
    }
    vector<pair<string, int>> ans(res.begin(), res.end());
    sort(ans.begin(), ans.end(), compare);

    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i].first << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    string* s = new string[N];

    for(int i = 0; i < N; i++){
        cin >> s[i];
    }

    solution(s, M, N);
}