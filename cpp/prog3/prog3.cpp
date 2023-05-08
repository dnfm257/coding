#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

// O(n) 복잡도
/*int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    vector<int> uniform(n + 2, 1); // 양끝쪽 공백

    for(int i = 0; i < reserve.size(); i++){
        uniform[reserve[i]]++;
    }
    for(int i = 0; i < lost.size(); i++){
        uniform[lost[i]]--;
    }

    for(int i = 1; i <= n; i++){
        if(uniform[i - 1] == 0 && uniform[i] == 2){ // 앞사람 먼저
            uniform[i - 1] = 1;
            uniform[i]--;
        }
        else if(uniform[i + 1] == 0 && uniform[i] == 2){ // 뒷사람
            uniform[i + 1] = 1;
            uniform[i]--;
        }
    }

    for(int i = 1; i <= n; i++){
        if(uniform[i] > 0){
            answer++;
        }
    }
    return answer;
}*/

// O(klogk) 복잡도 -> k < n
int solution(int n, vector<int> lost, vector<int> reserve){
    int answer = 0;
    unordered_set<int> l(lost.begin(), lost.end()); // 잃어버린 학생
    set<int> r; // 여벌로 가져온 학생(앞사람부터 지워나가야해서 순서있는 set)
    unordered_set<int> lr; // 여벌로 가져왔는데 잃어버린 학생

    for(auto& i : reserve){
        if(l.find(i) == l.end()){ // 여벌로 가져왔는데 잃어버리지 않음
            r.insert(i);
        }
        else{ // 여벌로 가져왔는데 잃어버림
            lr.insert(i);
        }
    }

    for(auto& x : lr){
        l.erase(x); // 여벌로 가져왔는데 잃어버린 학생 지우기
    }

    for(auto& i : r){
        if(l.find(i - 1) != l.end()){ // 앞사람 체크
            l.erase(i - 1);
        }
        else if(l.find(i + 1) != l.end()){ // 뒷사람 체크
            l.erase(i + i);
        }
    }

    answer = n - l.size();

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, p, b;

    cin >> n >> p >> b;

    vector<int> lost(p + 1, 0);
    vector<int> reserve(b + 1, 0);

    int a;
    for(int i = 0; i < p; i++){
        cin >> a;
        lost.emplace_back(a);
    }
    for(int i = 0; i < b; i++){
        cin >> a;
        reserve.emplace_back(a);
    }

    cout << solution(n, lost, reserve) << "\n";
}