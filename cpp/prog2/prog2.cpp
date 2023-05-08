#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes){
    int answer = 1;
    unordered_map<string, int> um;
    
    for(int i = 0; i < clothes.size(); i++){
        um[clothes[i][1]]++;
    }

    for(auto& i : um){
        cout << i.second << endl;
    }
    
    for(auto& i : um){
        answer *= i.second + 1;
    }
    
    return answer - 1;
}

int main(){
    vector<vector<string>> clothes;
    int N;

    cin >> N;
    string s1, s2;
    for(int i = 0; i < N; i++){
        cin >> s1 >> s2;
        clothes.push_back({s1, s2});
    }

    cout << solution(clothes) << endl;
}