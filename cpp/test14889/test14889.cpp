#include <iostream>
#include <vector>

using namespace std;

int chemi[21][21];
int N, S;
int visited[21];
vector<int> st;
vector<int> lnk;
int ans = 987654321;

void DFS(int x){
    if(x == N/2){
        int a, b = 0;

        for(int i = 1; i <= N; i++){
            if(!visited[i]){
                if(!lnk.empty()){
                    for(int j = 0; j < lnk.size(); j++){
                        b += chemi[lnk[j]][i] + chemi[i][lnk[j]];
                    }
                }
                lnk.push_back(i);
            }
            
            else{
                if(!st.empty()){
                    for(int j = 0; j < st.size(); j++){
                        a += chemi[st[j]][i] + chemi[i][st[j]];
                    }
                }
                st.push_back(i);
            }
        }

        if(ans > abs(a - b)){
            ans = abs(a - b);
        }

        return;
    }

    for(int i = 1; i <= N/2; i++){
        if(!visited[i]){
            visited[i] = true;
            DFS(x + 1);

            visited[i] = false;
        }   
    }
}

int main(){
    cin >> N;

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> chemi[i][j];
        }
    }

    DFS(0);

    cout << ans << "\n";
}