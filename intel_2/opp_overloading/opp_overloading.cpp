#include <iostream>
#include <algorithm>

using namespace std;

void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap(char* a, char* b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
}
void swap(short a[], short b[]){
    // 두 배열의 길이가 다르면 어캄...? => 함수로 해결..?
    int size_a = sizeof(a) / sizeof(short);
    int size_b = sizeof(b) / sizeof(short);

    short tmp[size_a];
    copy_n(a, size_a, tmp);

    copy_n(b, size_b, a);
    copy_n(tmp, size_a, b);    
}

void print(const char* a, int n){
    for(int i = 0; i < n; i++){
        cout << a << endl;
    }
}
void print(const char* a, const char* b){
    cout << a << b << endl;
}
void print(int x, int y){
    cout << x + y << endl;
}

int main(){
    int x = 1;
    int y = 5;
    char c1 = 'a';
    char c2 = 'f';
    swap(x, y);
    cout << x << ", " << y << "\n";

    swap(c1, c2);
    cout << c1 << ", " << c2 << "\n";

    const char* a = "hello";
    const char* b = "world!";
    swap(a, b);
    cout << a << ", " << b << "\n";

    print(a, 2);
    print(a, b);
    print(1, 2);

    return 0;
}