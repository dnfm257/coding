#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <stack>

using namespace std;

vector<string> solution(vector<vector<string>> tickets){
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), greater<vector<string>>());
    
    unordered_map<string, vector<string>> route;
    for(int i = 0; i < tickets.size(); i++){
        route[tickets[i][0]].push_back(tickets[i][1]);
    }
    
    stack<string> s;
    s.push("ICN");
    
    while(!s.empty()){
        string now = s.top();
        
        if(route[now].size() == 0 || route.find(now) == route.end()){
            answer.emplace_back(now);
            s.pop();
        }
        else{
            s.push(route[now].back());
            route[now].pop_back();
        }
    }
    reverse(answer.begin(), answer.end());

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int N;
    cin >> N;
    vector<vector<string>> tickets(N);

    string a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        tickets[i].emplace_back(a);
        tickets[i].emplace_back(b);
    }

    for(auto& i : solution(tickets)){
        cout << i << "\n";
    }
}