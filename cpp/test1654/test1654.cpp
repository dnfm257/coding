#include <iostream>
#include <vector>

using namespace std;

unsigned int K, N, ans;
vector<unsigned int> lan;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;

    unsigned int a;
    unsigned int mx;
    for(int i = 0; i < K; i++){
        cin >> a;
        lan.push_back(a);

        mx = max(mx, lan[i]);
    }

    unsigned int le = 1;
    unsigned int ri = mx;
    unsigned int mid;
    
    while(le <= ri){
        unsigned int cnt = 0;
        mid = (le + ri) / 2;

        for(int i = 0; i < K; i++){
            cnt += lan[i] / mid;
        }

        if(cnt < N){
            ri = mid - 1;
        }
        else{
            le = mid + 1;

            ans = max(ans, mid);
        }
    }

    cout << ans << "\n";
}