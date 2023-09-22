#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void fileRead(vector<string>& v, ifstream& fin){
    string line;

    while(getline(fin, line)){
        v.push_back(line);
    }
}

void search(vector<string>& v, string word){
    for(int i = 0; i < v.size(); i++){
        int idx = v[i].find(word);
        
        if(idx != -1){
            cout << v[i] << "\n";
        }
    }
}

int main(){
    vector<string> wordVector;
    ifstream fin("words.txt");
    if(!fin){
        cout << "word파일 열기 오류\n";
        return 0;
    }

    fileRead(wordVector, fin);
    fin.close();

    cout << "파일 읽기\n";

    while(true){
        cout << "검색단어: ";
        string word;
        getline(cin, word);

        if(word == "exit") break;

        search(wordVector, word);
    }

    cout << "프로그램 종료\n";
}