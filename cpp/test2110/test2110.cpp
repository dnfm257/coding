#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    int a;
    for(int i = 0; i < N; i++){
        cin >> a;
        home.push_back(a);
    }

    sort(home.begin(), home.end());

    int le = 1; // 최대 간격을 구하는 문제 = 최소간격은 1
    int ri = home.back();
    int ans = 0;
    while(le <= ri){
        int mid = (le + ri) / 2;
        int before = home[0];
        int cnt = 1; // 첫번째에 공유기 1개 이미 설치
        
        for(int i = 1; i < N; i++){
            if(home[i] - before >= mid){
                before = home[i];
                cnt++;
            }
        }

        if(cnt < C){
            ri = mid - 1;
        }
        else{
            le = mid + 1;
            ans = max(ans, mid);
        }
    }

    cout << ans << "\n";
}