#include <iostream>
#include <vector>

using namespace std;

int M, N, ans;
vector<int> tree;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int a;
    int mx = 0;
    for(int i = 0; i < N; i++){
        cin >> a;
        tree.push_back(a);

        mx = max(mx, tree[i]);
    }

    int le = 1;
    int ri = mx;
    while(le <= ri){
        int mid = (le + ri) / 2;
        long long int tmp = 0;

        for(int i = 0; i < N; i++){
            if(tree[i] <= mid){
                continue;
            }
            tmp += (tree[i] - mid);
        }

        if(tmp >= M){
            le = mid + 1;

            ans = max(ans, mid);
        }
        else{
            ri = mid - 1;
        }
    }

    cout << ans << "\n";
}