#include <iostream>

using namespace std;

int N;
int arr[1002];
int dp_1[1002];
int dp_2[1002];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp_1[i] = max(dp_1[j] + 1, dp_1[i]);
            }
            
            if(arr[N - i + 1] > arr[N - j + 1]){
                dp_2[N - i + 1] = max(dp_2[N - j + 1] + 1, dp_2[N - i + 1]);
            }
        }
    }

    for(int i = 1; i <= N; i++){
        dp_1[i] += dp_2[i] - 1;
    }

    int ans = 1;
    for(int i = 1; i <= N; i++){
        ans = max(ans, dp_1[i]);
    }

    cout << ans << "\n";
}