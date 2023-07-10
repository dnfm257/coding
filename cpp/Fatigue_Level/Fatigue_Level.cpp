#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer2 = 0;
int n;

void DFS(int f_lvl, int tmp, vector<vector<int>> dungeons, vector<bool>& visited){
    if(tmp > answer2){
        answer2 = tmp;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i] && f_lvl >= dungeons[i][0]){
            visited[i] = true;
            DFS(f_lvl - dungeons[i][1], tmp + 1, dungeons, visited);
            visited[i] = false;
        }
    }
}

int solution2(int k, vector<vector<int>> dungeons){
    n = dungeons.size();
    vector<bool> visited(n, false);

    DFS(k, 0, dungeons, visited);

    return answer2;
}

int solution(int k, vector<vector<int>> dungeons){
    int answer = 0;
    
    sort(dungeons.begin(), dungeons.end());

    do{
        int tmp = 0;
        int f_lvl = k;

        for(int i = 0; i < dungeons.size(); i++){
            if(f_lvl == 0){
                break;
            }
        
            if(f_lvl >= dungeons[i][0]){
                f_lvl -= dungeons[i][1];
                tmp++;
            }
        }
        answer = max(answer, tmp);
        
    } while(next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> K;

    cin >> N;
    vector<vector<int>> dungeons(N);

    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        dungeons[i].emplace_back(a);
        dungeons[i].emplace_back(b);
    }

    cout << solution(K, dungeons) << "\n";
    cout << solution2(K, dungeons) << "\n";
}