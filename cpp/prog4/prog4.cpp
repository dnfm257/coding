#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 포인터로 다음 위치 찾기 => 테스트 케이스 통과X
/*int movement(string name, string a, int& idx){
    int result = 0;
    int mov_l = idx;
    int cnt_l = 0;
    int mov_r = idx;
    int cnt_r = 0;
    while(name[mov_r] == a[mov_r]){
        mov_r++;
        cnt_r++;

        if(mov_r >= name.size()){
            mov_r = 0;
        }
    }
    while(name[mov_l] == a[mov_l]){
        mov_l--;
        cnt_l++;

        if(mov_l < 0){
            mov_l = name.size() - 1;
        }
    }

    if(cnt_l < cnt_r){
        idx = mov_l;
        result = cnt_l;
    }
    else{
        idx = mov_r;
        result = cnt_r;
    }

    return result;
}*/

// 글자 변경 이동 경우의 수 구하기
// 1. st -> i -> j -> ed => n - 1 (최대 경우의 수)
// 2. st -> i -> st -> ed -> j => 2*i + (n - j)
// 3. st -> ed -> j -> ed -> st -> i => i + 2(n - j)
int solution(string name){
    int answer = 0;
    string a = "";
    const int sz = name.length();
    int tmp = sz - 1;

    for(int i = 0; i < sz; i++){
        a += "A";
    }
    
    int idx = 0;
    while(idx <= sz - 1){
        answer += min('Z' + 1 - name[idx], name[idx] - 'A');
        a[idx] = name[idx];

        /*if(a == name){
            return answer + tmp;
        }

        answer += movement(name, a, idx);*/
        
        int idx_ed = idx + 1;

        while(idx_ed <= sz - 1 && name[idx_ed] == a[idx_ed]){
            idx_ed += 1;
        }

        tmp = min(tmp, (idx + sz - idx_ed + min(idx, sz - idx_ed)));
        idx++;
    }

    return answer + tmp;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name;
    cin >> name;

    cout << solution(name) << "\n";
}