#include <iostream>
#include <map>

using namespace std;

int arr[25] = {
	2, 2, 3, 6, 87,
	4, 2, 3, 68, 8,
	8, 8, 6, 7, 65,
	6, 8, 6, 8, 7,
	1, 5, 4, 5, 8
};

int main() {
	map<int, int> lst; // <num, count>

	for (int i = 0; i < (sizeof(arr) / sizeof(int)); i++) {
		if (lst.count(arr[i]) != 0) { // 이미 해당 key값이 존재할 경우
			lst[arr[i]]++; // 해당 key의 value값 +1
			continue;
		}

		lst.insert(make_pair(arr[i], 1)); // 없으면 삽입
	}

	for (auto iter = lst.begin(); iter != lst.end(); ++iter) {
		cout << iter->first << " |";

		for (int j = 0; j < iter->second; j++) {
			cout << "=";
		}

		cout << "(" << iter->second << ")\n";
	}

	return 0;
}