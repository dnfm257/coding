#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<vector<bool>> visited(5, vector<bool>(2, true));

    for(auto i : visited){
        for(auto j : i){
            cout << j << " ";
        }
        cout << endl;
    }
}