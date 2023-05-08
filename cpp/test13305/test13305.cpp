#include <iostream>
#include <vector>

using namespace std;

int N;
vector<long long> pric;
vector<long long> dist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    long long a;
    for(int i = 0; i < N - 1; i++){
        cin >> a;
        dist.push_back(a);
    }
    
    long long b;
    for(int i = 0; i < N; i++){
        cin >> b;
        pric.push_back(b);
    }

    long long now = pric[0];
    long long ans = 0;
    for(int i = 0; i < N - 1; i++){
        if(now > pric[i]){
            now = pric[i];
        }
        
        ans += dist[i] * now;
    }

    cout << ans << "\n";
}