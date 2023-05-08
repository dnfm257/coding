#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book){
    bool answer = true;
    unordered_map<string, bool> um;
    
    for(int i = 0; i < phone_book.size(); i++){
        um[phone_book[i]] = true;
    }
    
    for(int i = 0; i < phone_book.size(); i++){
        for(int j = 1; j < phone_book[i].size(); j++){
            string tmp = phone_book[i].substr(0, j);

            cout << tmp << endl;
            
            if(um[tmp]){
                answer = false;
                break;
            }
        }
    }
    
    return answer;
}

int main(){
    vector<string> phone_book;

    int N;

    cin >> N;
    string s;
    for(int i = 0; i < N; i++){
        cin >> s;
        phone_book.push_back(s);
    }

    cout << solution(phone_book) << endl;
}