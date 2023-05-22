#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool check_one(string a, string b){
    int cnt = 0;

    for(int i = 0; i < a.size(); i++){
        if(a[i] != b[i]){
            cnt++;
        }
    }

    if(cnt == 1){
        return true;
    }
    
    return false;
}

void DFS(string now, string target, vector<string> words, int step, vector<bool>& visited, int& answer){
    if(answer <= step){
        return;
    }
    
    if(now == target){
        answer = min(answer, step);
        return;
    }
    
    for(int i = 0; i < words.size(); i++){
        if(!visited[i] && check_one(words[i], now)){
            visited[i] = true;
            DFS(words[i], target, words, step + 1, visited, answer);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words){
    int answer = 50;
    vector<bool> visited(words.size());
    
    DFS(begin, target, words, 0, visited, answer);

    if(answer > words.size() + 1){
        answer = 0;
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string begin, target;
    cin >> begin >> target;

    int N;
    cin >> N;

    vector<string> words;

    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        words.emplace_back(s);
    }

    cout << solution(begin, target, words) << "\n";
}