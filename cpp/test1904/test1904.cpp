/*N = 1(경우의수)
1

N = 2
11(N1)
00

N = 3
111(N2)
001(N1)
100(N2)

N = 4
0011(N3)
0000(N2)
1001(N3)
1100(N2)
1111(N3)

dp[i] = dp[i - 2] + dp[i - 1]*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> dp;
int N;

int Dynamic(){
    dp.push_back(1);
    dp.push_back(2);

    int a;
    for(int i = 2; i < N; i++){
        a = dp[i - 1] + dp[i - 2];
        dp.push_back(a % 15746);
    }

    return dp[N];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    cout << Dynamic() << "\n";
}