#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int solution(vector<int> people, int limit){
    int answer = 0;
    deque<int> tmp(people.begin(), people.end());
    
    sort(tmp.begin(), tmp.end());

    while(!tmp.empty()){
        if(tmp.size() == 1){
            answer++;
            break;
        }
        if(tmp.front() + tmp.back() <= limit){
            tmp.pop_front();
        }
        tmp.pop_back();
        answer++;
    }
    
    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> people;
    int limit = 0;
    int N = 0;

    cin >> N;

    int a = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        people.emplace_back(a);
    }
    cin >> limit;

    cout << solution(people, limit) << "\n";
}