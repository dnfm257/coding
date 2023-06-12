#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow){
    vector<int> answer;

    int tmp = (brown / 2) + 2;

    for(int i = 1; i <= tmp / 2; i++){
        if(i - 2 < 0){
            continue;
        }
        if((tmp - i - 2) * (i - 2) == yellow){
            answer.emplace_back(tmp - i);
            answer.emplace_back(i);
            break;
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int B, Y;
    cin >> B >> Y;

    for(auto &i : solution(B, Y)){
        cout << i << " ";
    }
    cout << "\n";
}