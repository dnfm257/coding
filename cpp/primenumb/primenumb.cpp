#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num){
    if(num < 2){
        return false;
    }
    
    // 에라토스테네스의 체
    for(int i = 2 ; i <= sqrt(num); i++){
        if(num % i == 0){
            return false;
        }
    }

    return true;
}

int solution(string numbers){
    unordered_set<int> answer;
    int tmp = 0;

    sort(numbers.begin(), numbers.end());

    do{
        for(int i = 0; i < numbers.size(); i++){
            tmp = stoi(numbers.substr(0, i)); // int 형변환
        }

        if(isPrime(tmp)){
            answer.insert(tmp);
        }
    } while(next_permutation(numbers.begin(), numbers.end())); // 순열 => 순서섞기

    return answer.size();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string numbers;
    cin >> numbers;

    cout << solution(numbers) << "\n";
}