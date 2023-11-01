#include <iostream>
#include <vector>

using namespace std;

int N;
int max_value = -1000000001;
int min_value = 1000000001;

void backTracking(int cnt, vector<int> op, vector<int>& visited, int res, int* arr){
    if(cnt == N - 1){ // 다 뽑으면
        max_value = max(res, max_value);
        min_value = min(res, min_value);
        return;
    }

    for (int i = 0; i < N - 1; i++) {
        if(visited[i] == 1) continue;
        visited[i] = 1;

        if(op[i] == 0) 
            backTracking(cnt+1, op, visited, (res + arr[cnt+1]), arr);
        else if(op[i] == 1) 
            backTracking(cnt+1, op, visited, (res - arr[cnt+1]), arr);
        else if(op[i] == 2) 
            backTracking(cnt+1, op, visited, (res * arr[cnt+1]), arr);
        else 
            backTracking(cnt+1, op, visited, (int)(res / arr[cnt+1]), arr);

        visited[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int* arr = new int[N];
    vector<int> op;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int tmp = 0;
    for (int i = 0; i < 4; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            op.push_back(i);
        }
    }

    vector<int> visited(N - 1, 0);
    int res = arr[0];
    
    backTracking(0, op, visited, res, arr);
    cout << max_value << "\n" << min_value << "\n";
}