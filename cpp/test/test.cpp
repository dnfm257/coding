#include <iostream>

using namespace std;

int main(){
    bool visited[5][2] = { false };

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 2; j++){
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}