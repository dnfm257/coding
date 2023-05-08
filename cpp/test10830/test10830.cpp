#include <iostream>

using namespace std;

long long N, B;
long long mat[5][5];
long long ans[5][5];

void multiple(long long a[5][5], long long b[5][5]){
    long long tmp[5][5];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            tmp[i][j] = 0;
            for(int k = 0; k < N; k++){
                tmp[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            a[i][j] = tmp[i][j] % 1000;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> B;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> mat[i][j];
        }
        ans[i][i] = 1; // 단워행렬
    }

    while(B > 0){
        if(B % 2 == 1){
            multiple(ans, mat); // E * A = A
        }

        multiple(mat, mat); // A * A = A^2
        B /= 2;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}