#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k){
    const int siz = number.length();
    string answer = "";
    
    int idx = 0;
    while(answer.length() < siz - k){
        int mx = 0;

        for(int i = idx; i <= k + answer.length(); i++){
            if(mx < number[i] - '0'){
                mx = number[i] - '0';
                idx = i + 1;
            }
        }

        answer += to_string(mx);
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string number = "";
    int k = 0;

    cin >> number;
    cin >> k;

    cout << solution(number, k) << "\n";
}